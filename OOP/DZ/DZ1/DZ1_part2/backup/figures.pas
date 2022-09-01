unit figures;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils,Forms,Controls,Graphics,Dialogs, ExtCtrls, math;
 type
Tfigure=class
       x,y,dx,dy,halflen:integer;
       Image:timage;
       constructor create (ix,iy,ihalflen:integer; iImage:TImage);
       procedure move(t:single);
       procedure draw ();virtual;abstract;
       procedure rel (t:single);
end;
Tround = class (tfigure)
       procedure draw();override;
end;
TYgolnik_6 = class (tfigure)
           delta_x,delta_y:integer;
           constructor create (ix,iy,ihalflen:integer; iImage:TImage);
           procedure draw();override;
end;
TAstroida = class (tfigure)
          procedure draw (); override;
end;

implementation
constructor Tfigure.create(ix,iy,ihalflen:integer; iImage:TImage);
begin
     x:=ix; y:=iy; halflen := ihalflen; Image := iImage;
end;
procedure tfigure.move(t:single);
begin
     image.Canvas.Pen.Width:=5;
     Image.canvas.pen.color := clhighlight;
     Draw;
     Rel(t);
     Image.canvas.pen.color := clAqua;
     Draw;
end;
procedure tfigure.Rel(t:single);
begin
     dy := round(t);
   {  dx := round(halflen * cos(t) );
     dy := round (halflen * sin(t) );    }
end;
// Figures
procedure Tround.Draw();
begin
     //Если рисуется не ровно, добавить радиус в поля
     Image.canvas.ellipse(x+dx+halflen, y+dy+halflen, x+dx-halflen, y+dy-halflen);
end;
constructor Tygolnik_6.create (ix,iy,ihalflen:integer; iImage:TImage);
begin
     inherited create (ix,iy,ihalflen, iImage);
     delta_x := round ( ihalflen * sqrt (2) / 2 );
     delta_y := round( ihalflen * sqrt(3) / 2 );
end;
procedure Tygolnik_6.Draw();
begin
    // image.canvas.moveto (x+dx-100,y+dy-100);
    // image.canvas.lineto(x+dx+100,y+dy+100);
    // image.canvas.brush.color:=clblack;
   //  image.canvas.rectangle(350,300,800,100);
   //  image.canvas.brush.color:=clhighlight;
     image.canvas.moveto (x+dx,y+dy);
     image.canvas.lineto ( x + dx - delta_x, y + dy - delta_y );
     image.canvas.lineto ( x + dx - delta_x - halflen , y + dy - delta_y );
     image.canvas.lineto ( x + dx - 2 * delta_x - halflen, y + dy );
     image.canvas.lineto ( x + dx - delta_x - halflen, y + dy + delta_y );
     image.canvas.lineto ( x + dx - delta_x, y + dy + delta_y);
     image.canvas.lineto ( x + dx, y + dy);
end;
procedure TAstroida.Draw ();
var i : single = 0.0;
  first:boolean=true;
  nx,ny:integer;
begin
     while i<=6.28 do
           begin
           nx:=x+dx+trunc(halflen*cos(i)*cos(i)*cos(i));
           ny:=y+dy+trunc(halflen*sin(i)*sin(i)*sin(i));
           if first then begin
           image.canvas.moveto(nx,ny);
           first:=false;
           end;
           image.Canvas.lineto(nx,ny);
           i:=i+0.01;
           end;
end;
end.


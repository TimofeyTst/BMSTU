unit graphic_form;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls,
  Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TGraphic_trams }
  TGraphic_trams = class(TForm)
    Button1: TButton;
    Button5: TButton;
    Image1: TImage;
    procedure Button1Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure FormActivate(Sender: TObject);
  private

  public

  end;
var
  Graphic_trams: TGraphic_trams;

implementation
uses data_base_form,main_form;
{$R *.lfm}

{ TGraphic_trams }

procedure TGraphic_trams.Button5Click(Sender: TObject);
begin
     graphic_trams.close;
     data_base.setfocus;
     data_base.button3.Enabled:=true;
end;

procedure TGraphic_trams.FormActivate(Sender: TObject);
begin
     image1.canvas.pen.width:=1;
     image1.Canvas.Brush.Color:=clWhite;
     image1.canvas.Pen.Color:=clblue;
     image1.Canvas.Rectangle(-1,-1,1000,1000);
end;

procedure TGraphic_trams.Button1Click(Sender: TObject);
var
  i,j,dx,dy,size,count,help:integer;
  left_down,right_top:tpoint;
  s:string;
  rec:metro_member;
  const n = 10; //n ~ Smesh text
  const d = 5; // d ~ ++ about x
  const first = 2000; // first ~ 1st x
begin
     left_down.Create(30,290);
     right_top.Create(502,5);
     dx:=40; dy:=40;
     size := filesize(f);
     image1.canvas.Pen.Color:=clblue;
     image1.canvas.pen.width:=1;
     image1.Canvas.MoveTo(left_down);
     //Draw scheme
     for i:=0 to trunc((right_top.x-left_down.X)/dx) do begin
         s:=inttostr(i*d+first);
         image1.canvas.TextOut(left_down.X+dx*i-n,left_down.y+n,s);
         //horizontal
         s:=inttostr(i);
         image1.canvas.TextOut(left_down.x-n,left_down.y-dy*i-n,s);
         image1.canvas.moveto(left_down.x,left_down.y-dy*i);
         image1.canvas.lineto(right_top.X,left_down.y-dy*i);
         //vertical
         image1.canvas.moveto(left_down.x+dx*i,left_down.y);
         image1.canvas.lineto(left_down.X+dx*i,right_top.Y);
     end;
     image1.canvas.MoveTo(left_down);
     image1.canvas.Pen.Color:=clyellow;
     image1.canvas.pen.width:=5;
     //Podc4et < min
     reset(f);
     count := 0;
     for i:=0 to size-1 do begin
         read(f,rec);
         if rec.birthday < first then count := count +1;
     end;
     image1.canvas.moveto(left_down.x,left_down.y-count*dy);
     // end. Pods4et norm:
     help:=0;
      for i:=0 to trunc((right_top.x-left_down.X)/dx-2) do begin
          reset(f);
          count :=0;
          for j:=0 to size-1 do begin
              read(f,rec);
              if (rec.birthday < (i+1)*d+first) and (rec.birthday >= i*d+first) then
              count := count + 1;
          end;
          help:=help+1;
          image1.canvas.lineto(left_down.x+(i+1)*dx,left_down.Y-count*dy);
     end;
     //end. Pods4et > max
     reset(f);
     count := 0;
     j:=first + d * trunc((right_top.x-left_down.X)/dx);
     for i:=0 to size-1 do begin
              read(f,rec);
              if rec.birthday > j then count := count +1;
         end;
     j:=trunc((right_top.x-left_down.X)/dx);
     image1.canvas.lineto(left_down.x+j*dx,left_down.y-count*dy);
end;

end.


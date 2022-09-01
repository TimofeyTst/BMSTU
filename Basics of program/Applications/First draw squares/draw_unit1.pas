unit draw_unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Image1: TImage;
    procedure CleanClick(Sender: TObject);
    procedure ExitClick(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure Image1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );
    procedure Image1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
  private

  public

  end;

var
  Form1: TForm1;

implementation
var rect:Trect; Key:boolean=false;
{$R *.lfm}

{ TForm1 }

procedure TForm1.Image1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
     if button=mbleft then begin
        rect.Left:=x;
        rect.Top:=y;
        key:=true;
     end;
end;

procedure TForm1.Image1MouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
      if ssleft in shift then begin
         image1.Canvas.Brush.Color:=clblack;
         if key then key:=false
         else begin
             image1.Canvas.Pen.Color:=clblack;
             image1.canvas.Rectangle(rect.left,rect.Top,rect.Right,rect.Bottom);
         end;
      rect.Right:=x;
      rect.Bottom:=y;
      image1.canvas.pen.color:=clwhite; //brush test
      image1.canvas.Rectangle(rect.left,rect.Top,rect.Right,rect.Bottom);
      end;
end;

procedure TForm1.Image1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
     if button=mbLeft then begin
         image1.Canvas.Pen.color:=clblack;
         image1.canvas.Rectangle(rect.left,rect.top,rect.right,rect.bottom);
         rect.Right:=x;
         rect.Bottom:=y;
         image1.Canvas.Brush.color:=clred;
         image1.canvas.FillRect(rect);
         Image1.Canvas.brush.Color:=clblack;
         image1.canvas.pen.color:=clwhite;

     end;
end;

procedure TForm1.ExitClick(Sender: TObject);
begin
     close;
end;

procedure TForm1.CleanClick(Sender: TObject);
begin
     image1.Canvas.Clear;
end;

procedure TForm1.FormActivate(Sender: TObject);
begin
     image1.Canvas.Brush.color:=clwhite;
end;

end.


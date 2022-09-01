unit Part1_unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls,my_math;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    UpDown1: TUpDown;
    UpDown2: TUpDown;
    procedure Button2Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure ExitClick(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure Image1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Image1MouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );
    procedure Image1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure RadioButton1Click(Sender: TObject);
    procedure RadioButton2Click(Sender: TObject);

  end;

var
  Form1: TForm1;
  a:integer=1;

implementation
 var
 choose:integer=1;
 key : boolean = false;
 point_n,point_k:tpoint;
 w:integer;
 Line_round:line_with_round;
{$R *.lfm}

{ TForm1 }

procedure TForm1.ExitClick(Sender: TObject);
begin
     Close;
end;

procedure TForm1.Edit1Change(Sender: TObject);
var code:integer;
begin
     val(edit1.text,w,code);
     image1.canvas.Pen.Width:=w;
end;

procedure TForm1.Edit2Change(Sender: TObject);
var code:integer;
begin
     val(edit2.Text,w,code);
     a:=w;
     s := round ( a/3 );
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     image1.canvas.Clear;
end;

procedure TForm1.FormActivate(Sender: TObject);
begin
     image1.Canvas.Brush.Color:=clwhite;
     image1.canvas.Rectangle(-1,-1,10000,10000);
     image1.canvas.pen.Width:=10;
    // image1.Color:=clwhite;
    // image1.Canvas.brush.Color:=clgreen;
end;


procedure TForm1.Image1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
      if button = mbleft then begin
        key:=true;
        point_n.x:=x;
        point_n.y:=y;
     end;
end;

procedure TForm1.Image1MouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
      if ssleft in shift then begin
       // image1.Canvas.Pen.Color:=clblack;
        if key then key:=false
        else begin
           image1.canvas.pen.color:=clwhite;
           //Image1.canvas.lineto(point_k);
           image1.canvas.line(point_n,point_k);
        end;
     point_k.x:=x;
     point_k.y:=y;
     image1.canvas.pen.color:=clred;
     //image1.Canvas.LineTo(point_k);
     image1.Canvas.line(point_n,point_k);
     end;
end;

procedure TForm1.Image1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var code:integer=0;
begin
     case choose of
     1:
      if button = mbleft then begin
     point_k.x:=x;
     point_k.y:=y;
     image1.canvas.pen.color:=clAqua;
     image1.canvas.line(point_n,point_k);
     end;
     2:
       if button = mbleft then begin
     point_k.x:=x;
     point_k.y:=y;
     line_round.begin_init(point_n);
     line_round.end_init(a,point_k);
     //
     image1.canvas.pen.color:=clAqua;
     image1.canvas.line(point_n,point_k);

     image1.canvas.Brush.Color:=clwhite;
     //image1.canvas.Pen.Width:=2;
     Image1.canvas.Ellipse(line_round.point_n_round.x,line_round.point_n_round.y,
     line_round.point_k_round.x,line_round.point_k_round.y);
     val(edit1.text,w,code);
     image1.canvas.Pen.Width:=w;
      end;
     end;
end;

procedure TForm1.RadioButton1Click(Sender: TObject);
begin
     choose:=1;
end;

procedure TForm1.RadioButton2Click(Sender: TObject);
begin
     choose:=2;
end;

end.


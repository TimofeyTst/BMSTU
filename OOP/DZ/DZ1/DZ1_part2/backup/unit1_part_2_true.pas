unit unit1_part_2_true;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  figures, math;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Image1: TImage;
    Timer1: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}
var
  key:boolean = false;
  pause:boolean = false;
  smena1,smena2,smena3: boolean;
  i:integer = 0;
  t1,t2,t3:single;
  Round:Tround;
  Ygolnik_6:Tygolnik_6;
  Astroida:Tastroida;

{ TForm1 }

procedure TForm1.FormActivate(Sender: TObject);
begin
     button2.Enabled:=false;
     timer1.Enabled:=false;
     image1.Canvas.Brush.Color:=clhighlight;
     image1.canvas.Rectangle(-2,-2,1000,1000);
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
     Round.move(t1);
     Ygolnik_6.move (t2);
     // {For astroida}image1.canvas.Pen.color:=clhighlight;
     // {For astroida}image1.canvas.Rectangle(570,300,720,100);
     // {For astroida}image1.canvas.Pen.color:=claqua;
     Astroida.move(t3);


     if smena1 then begin
     t1:= t1 - 1;
     if  ( trunc (t1) = -80 ) then smena1 := false;
     end
     else begin
     t1 := t1 + 1;
     if (trunc (t1) = 80 ) then smena1 := true;
     end;

     if smena2 then begin
     t2:= t2 - 1;
     if  ( trunc (t2) = -120 ) then smena2 := false;
     end
     else begin
     t2 := t2 + 1;
     if (trunc (t2) = 120 ) then smena2 := true;
     end;
     
     if smena3 then begin
     t3:= t3 - 8;
     if  ( trunc (t3) = -120 ) then smena3 := false;
     end
     else begin
     t3 := t3 + 8;
     if (trunc (t3) = 120 ) then smena3 := true;
     end;

end;

procedure TForm1.Button3Click(Sender: TObject);
begin
     close;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
     if key then begin
       Round.free;
       ygolnik_6.free;
       Astroida.free;
       key:=false;
     end;
     Round := TRound.create ( 120,200,50,Image1 );
     Ygolnik_6 := TYgolnik_6.create( 410,200,50,Image1 );
     Astroida := TAstroida.create( 570,200,50,Image1 );
     Timer1.Enabled := True;
     button1.Enabled:=false;
     button2.Enabled:=true;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     if not(pause) then begin
     timer1.Enabled:=false;
     button2.Caption:='Continue';
     pause:=true;
     end
     else begin
           timer1.Enabled:=true;
           button2.Caption:='Pause';
           pause:=false;
     end;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
     timer1.Enabled:=false;
     Image1.canvas.Clear;
     button1.Enabled:=True;
     button2.Enabled:=false;
     button2.Caption:='Pause';
     pause:=false;
     key:=true;
end;


initialization
smena1:=false; t1 := 0.0;
smena2:=false; t2 := 0.0;
smena3:=false; t3 := 0.0;
finalization

Round.free;
ygolnik_6.free;
Astroida.free;

end.



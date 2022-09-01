unit Schet_unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ComCtrls, StdCtrls, Types;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    UpDown1: TUpDown;
    procedure Exit_click(Sender: TObject);
    procedure Clean_click(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure UpDown1Click(Sender: TObject; Button: TUDBtnType);
  private

  public

  end;

  const k=2;
var
  Form1: TForm1;
  n1,n2,n3:integer;
  s:string;
implementation

{$R *.lfm}

{ TForm1 }



procedure TForm1.UpDown1Click(Sender: TObject; Button: TUDBtnType);
begin
     val(edit1.text,n1);
     if n1=k then begin
     n1:=0;
     n2:=n2+1;
     if n2=k then begin
     n2:=0;
     n3:=n3+1;
     str(n3,s);
     edit3.text:=s;
     end;
     str(n2,s);
     edit2.text:=s;
     end;
     str(n1,s);
     edit1.text:=s;
end;

procedure TForm1.Clean_click(Sender: TObject);
begin
     edit1.text:='0';
     edit2.text:='0';
     edit3.text:='0';
     n1:=0;
     n2:=0;
     n3:=0;
end;

procedure TForm1.FormActivate(Sender: TObject);
begin
     edit1.readonly:=true;
     edit2.readonly:=true;
     edit3.readonly:=true;
     edit1.text:='0';
     edit2.text:='0';
     edit3.text:='0';
     n1:=0;
     n2:=0;
     n3:=0;
end;

procedure TForm1.Exit_click(Sender: TObject);
begin
  close;
end;

end.


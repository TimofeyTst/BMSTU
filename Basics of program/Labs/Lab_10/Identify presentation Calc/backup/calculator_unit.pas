unit Calculator_Unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Edit1: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
var sum:real;
    operation:char='@';
    procedure operate;
    var s:string;
        code:integer;
        n:real;
    begin
         s:=form1.edit1.text;
         Form1.Edir1.clear;
         val(s,n,code);
         case operation of
         '@': sum:=n;
         '+': sum:=sum+n;
         '-': sum:=sum-n;
         '*': sum:=sum*n;
         '/': sum:=sum/n;
         end;
    end;
{$R *.lfm}

    { TForm1 }

    procedure TForm1.Button1Click(Sender: TObject);
    begin
         edit1.clear;
         operation:='@';
         Edit1.setfocus;
    end;

procedure TForm1.Button2Click(Sender: TObject);
var s:string;
begin
     operate;
     str(sum:6:3,s);
     Edit1.text:=s;
     operation:='@';
     Edit1.setfocus;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
     operate;
     operation:='+';
     edit1.setfocus;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
     operate;
     operation:='-';
     Edit1.setfocus;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
     operate;
     operation:='*';
     edit1.setfocus;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
     operate;
     operation:='/';
     edit1.setfocus;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
     close;
end;

end.


unit Calc_TST_Unit;

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
    procedure DelClick(Sender: TObject);
    procedure ExitClick(Sender: TObject);
    procedure ProizvClick(Sender: TObject);
    procedure RavClick(Sender: TObject);
    procedure CleanClick(Sender: TObject);
    procedure RazClick(Sender: TObject);
    procedure SumClick(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
var view:single;
    operation:char='=';
{$R *.lfm}

{ TForm1 }

procedure calculation;
var s:string;
       code:integer;
       res:single;
       begin
            s:=form1.edit1.text;
            Form1.edit1.clear;
            val(s,res,code);
            case operation of
            '=': view:=res;
            '+': view:=view+res;
            '-': view:=view-res;
            '*': view:=view*res;
            '/': view:=view/res;
            end;
       end;

procedure TForm1.RavClick(Sender: TObject);
var s:string;
begin
     calculation;
     str(view:6:3,s);
     Edit1.text:=s;
     operation:='=';
     edit1.setfocus;
end;

procedure TForm1.ProizvClick(Sender: TObject);
begin
     calculation;
     operation:='*';
     Edit1.setfocus;
end;

procedure TForm1.DelClick(Sender: TObject);
begin
     calculation;
     operation:='/';
     Edit1.setfocus;
end;

procedure TForm1.ExitClick(Sender: TObject);
begin
     close;
end;

procedure TForm1.CleanClick(Sender: TObject);
begin
     edit1.clear;
     operation:='=';
     Edit1.setfocus;
end;

procedure TForm1.RazClick(Sender: TObject);
begin
     calculation;
     operation:='-';
     Edit1.setfocus;
end;

procedure TForm1.SumClick(Sender: TObject);
begin
      calculation;
      operation:='+';
      Edit1.setfocus;
end;


end.


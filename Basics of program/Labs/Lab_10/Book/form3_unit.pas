unit Form3_unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;
type

  { TForm3 }

  TForm3 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button4: TButton;
    Button5: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    StaticText3: TStaticText;
    StaticText4: TStaticText;
    procedure clear_click(Sender: TObject);
    procedure Exit_click(Sender: TObject);
    procedure Menu_click(Sender: TObject);
    procedure Searchbut_click(Sender: TObject);
  private

  public

  end;

var
  Form3: TForm3;

implementation
uses form1_unit;
{$R *.lfm}

{ TForm3 }

procedure TForm3.Menu_click(Sender: TObject);
begin
     closefile(f);
     close;
     form1.Show;
     form1.SetFocus;
end;

procedure TForm3.Searchbut_click(Sender: TObject);
var s:string[22];
  poisk:boolean;
begin
     edit1.Enabled:=false;
     reset(f);
     button2.Enabled:=false;
     poisk:=true;
     s:=edit1.Text;
     while not(eof(f)) and poisk do begin
     read(f,add);
     if add.fname=s then begin
         edit2.text:=add.sname;
         edit3.text:=add.tel;
         edit4.Text:=add.Adress;
         poisk:=false;
     end;
     end;
     if poisk then begin
         edit2.text:='No information';
         edit3.text:='No information';
         edit4.Text:='No information';
         end;
end;

procedure TForm3.clear_click(Sender: TObject);
begin
     edit1.Clear;
     edit2.clear;
     edit3.clear;
     edit4.Clear;
     edit1.Enabled:=true;
     button2.Enabled:=true;
     edit1.setfocus;
end;

procedure TForm3.Exit_click(Sender: TObject);
begin
     close;
     form1.close;
end;

end.


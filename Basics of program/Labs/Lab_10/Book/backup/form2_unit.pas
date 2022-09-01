unit Form2_unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;
type


  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    StaticText3: TStaticText;
    StaticText4: TStaticText;
    procedure Add_note_click(Sender: TObject);
    procedure Delete_click(Sender: TObject);
    procedure Exit_click(Sender: TObject);
    procedure Menu_click(Sender: TObject);
  private

  public

  end;

var
  Form2: TForm2;

implementation
uses form1_unit;
{$R *.lfm}

{ TForm2 }

procedure TForm2.Menu_click(Sender: TObject);
begin
     closefile(f);
     close;
     form1.show;
     form1.setfocus;
end;

procedure TForm2.Exit_click(Sender: TObject);
begin
      closefile(f);
      close;
end;

procedure TForm2.Add_note_click(Sender: TObject);
begin
     add.fname:=edit1.Text;
     add.sname:=edit2.Text;
     add.tel:=edit3.text;
     add.Adress:=edit4.Text;
     write(f,add);
     edit1.Clear;
     edit2.clear;
     edit3.clear;
     edit4.clear;
end;

procedure TForm2.Delete_click(Sender: TObject);
var key:boolean;
begin
     key:=Messagedlg('WARNING! Will be deleted ALL notes! Are you sure?', mtConfirmation,mbYesNo,0)=mrYes;
     if key then
        rewrite(f);
end;

end.


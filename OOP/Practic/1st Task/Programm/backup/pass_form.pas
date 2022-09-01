unit Pass_form;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TPassword }

  TPassword = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Edit1KeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure FormShow(Sender: TObject);
  private

  public

  end;

var
  Password: TPassword;
  var tries:integer=3;

implementation
uses main_form,form_dedit;
{$R *.lfm}

{ TPassword }

procedure TPassword.Edit1KeyUp(Sender: TObject; var Key: Word;
  Shift: TShiftState);
var s:string;
begin
      if (key = 13) then begin
          if (edit1.Text = pass) then begin
          password.close;
          edit1.Text := '';
          Access.show;
          access.setfocus;
     end
     else begin
       tries:=tries-1;
       if tries < 1 then begin
       messagedlg('Please, think about your behavior... Hacker', mterror, [],0);
       password.Close;
       end
       else begin
       s:='Are u have Access?! '+inttostr(tries)+' try left';
       messagedlg(s, mterror, mbokcancel,0);
       end;
     end;
      end;
end;

procedure TPassword.FormShow(Sender: TObject);
begin
     edit1.SetFocus;
end;


procedure TPassword.Button1Click(Sender: TObject);
begin
     password.close;
     access.close;
     edit1.Text := '';
     main.Show;
     main.SetFocus;
end;

end.


unit Main_Form;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics,
  Dialogs, StdCtrls, pass_form, data_base_form,graphic_form;

type
  metro_member = record
      Inv_num,birthday,life_time:word;
      model:string[15];
  end;

  { TMain }

  TMain = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Main: TMain;
  pass:string[20] = '0957';
  f:file of metro_member;
implementation
{$R *.lfm}
 {procedure metro_member.init (iInv_num,ibirthday,ilife_time:word;imodel:string);
 begin
        Inv_num:=iInv_num;
        birthday := ibirthday;
        life_time := ilife_time;
        model := imodel;
 end;
 procedure metro_member.print;
 begin
      writeln ('Inv number: ', inv_num, ' | Model: ',model, ' | Year production: ',birthday, ' | Life time: ',life_time);
 end;    }
{ TMain }

procedure TMain.Button1Click(Sender: TObject);
begin
     Main.hide;
     password.show;
end;

procedure TMain.Button2Click(Sender: TObject);
begin
     main.hide;
     data_base.Show;
end;

procedure TMain.Button3Click(Sender: TObject);
begin
     data_base.Close;
     password.Close;
     main.Close;
end;

end.


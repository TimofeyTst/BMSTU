unit Form1_unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls,
  form2_unit,form3_unit;
type
    zap=record
    fname:string[22];
    sname:string[22];
    tel:string[12];
    Adress:string[22];
  end;
  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label1: TLabel;
    procedure Add_notes_click(Sender: TObject);
    procedure Exit_click(Sender: TObject);
    procedure Searzh_note_click(Sender: TObject);
  private
  public
  end;

var
  Form1: TForm1;
  f:file of zap;
  add:zap;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Add_notes_click(Sender: TObject);
var size:integer;
begin
     Assignfile(f,'Notebook.txt');
     {$I-} Reset(f); {$I+}
     if IOresult=0 then begin
        size:=filesize(f);
        seek(f,size);
     end
     else rewrite(f);
     Hide;
     form2.show;
     form2.setfocus;
end;

procedure TForm1.Exit_click(Sender: TObject);
begin
     close;
end;

procedure TForm1.Searzh_note_click(Sender: TObject);
begin
     Assignfile(f,'Notebook.txt');
     {$I-} Reset(f); {$I+}
     if IOresult=0 then
        if filesize(f)<>0 then begin
       hide;
       form3.Edit2.Enabled:=false;
       form3.Edit3.Enabled:=false;
       form3.Edit4.Enabled:=false;
       form3.show;
       form3.setfocus;
       end
       else begin
         closefile(f);
         messagedlg('FIle is empty',mtError,[mbok],0);
       end
     else messagedlg('FIle is empty',mtError,[mbok],0);
end;

end.


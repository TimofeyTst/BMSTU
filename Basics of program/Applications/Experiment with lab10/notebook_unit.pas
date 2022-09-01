unit Notebook_unit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics,
  Dialogs, StdCtrls;
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
    procedure FormCreate(Sender: TObject);
    procedure Menu_click(Sender: TObject);
    procedure Searchbut_click(Sender: TObject);
  private
  public
  end;
var
  Form1: TForm1;
  Form2: TForm2;
  Form3: TForm3;
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
     if IOresult=0 then begin
       hide;
       form3.Edit2.Enabled:=false;
       form3.Edit3.Enabled:=false;
       form3.Edit4.Enabled:=false;
       form3.show;
       form3.setfocus;
       end
     else messagedlg('FIle is empty',mtError,[mbok],0);
end;
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
     form1.show;
     form1.setfocus;
end;

procedure TForm3.FormCreate(Sender: TObject);
begin

end;
end.

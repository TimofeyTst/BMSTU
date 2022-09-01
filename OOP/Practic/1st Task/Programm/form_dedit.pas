unit Form_dedit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics,
  Dialogs, StdCtrls, Grids, ComCtrls;

type

  { TAccess }

  TAccess = class(TForm)
    Button1: TButton;
    Button10: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    StringGrid1: TStringGrid;
    procedure Button10Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private

  public

  end;

var
  Access: TAccess;

implementation
uses main_form;
{$R *.lfm}

{ TAccess }

procedure TAccess.Button4Click(Sender: TObject);
begin
     closefile(f);
     access.Close;
     main.show;
     main.SetFocus;
end;

procedure TAccess.Button5Click(Sender: TObject);
var rec:metro_member;
  code:integer=0;
  s:string;
begin
     val(edit1.Text,rec.Inv_num,code);
     rec.model:=edit2.Text;
     val(edit3.Text,rec.birthday);
     val(edit4.text,rec.life_time);
     write(f,rec);
     edit1.clear;
     edit2.clear;
     edit3.clear;
     edit4.clear;
     str(filesize(f),s); edit6.text:=s; edit5.text:=s;
end;

procedure TAccess.Button6Click(Sender: TObject);
begin
     button5.Enabled:=false;
     button6.enabled:=false;
     edit5.Enabled:=true;
     button7.Enabled:=true;
end;

procedure TAccess.Button7Click(Sender: TObject);
var rec,rec_main:metro_member;
  code,vsp,pos,size,i:integer;
  Add_to_end:boolean = false;
  s:string;
  Vrem:file of metro_member;
begin
     size := filesize(f);
     val (edit5.text,pos,code);
     if pos > size then begin
        Add_to_end:=Messagedlg('Position more than size of file. Add to end?', mtConfirmation,mbYesNo,0)=mrYes;
        if add_to_end then button5.Click;
     end
     else begin
     val(edit1.Text,rec_main.Inv_num,code);
     rec_main.model:=edit2.Text;
     val(edit3.Text,rec_main.birthday);
     val(edit4.text,rec_main.life_time);
     //Rewrite after

     closefile(f);
     rename(f,'Data_base_edit.txt');
     reset(f);
     Assignfile(Vrem,'Data_base.txt');
     rewrite(Vrem);
     vsp := pos;
     for i:=1 to vsp do begin
         read(f,rec);
         write(Vrem,rec);
     end;
     write(Vrem,rec_main);
     vsp := size - pos;
     for i:=1 to vsp do begin
         read(f,rec);
         write(Vrem,rec);
     end;
     closefile(Vrem);
     closefile(f);
     erase(f);
     Assignfile(f,'Data_base.txt');
     Reset(f);
     seek(f,filesize(f));
     str(filesize(f),s); edit6.text:=s; edit5.text:=s;
     //that
     button7.Enabled:=false;
     button5.Enabled:=true;
     button6.enabled:=true;
     edit5.Enabled:=false;
     str(filesize(f),s); edit6.text:=s; edit5.text:=s;
     edit1.clear;
     edit2.clear;
     edit3.clear;
     edit4.clear;
     end;
end;

procedure TAccess.Button8Click(Sender: TObject);
var s:string;
    count,pos,vsp,size,i:integer;
    rec:metro_member;
    uncorrect:boolean=false;
    Vrem:file of metro_member;
begin
     size := filesize(f);
     if size <> 0 then begin
        val(edit6.text,pos,vsp);
        val(edit7.text,count,vsp);
        //Proverki
        if (count = 0) or ( pos = 0) then
           messagedlg('Uncorrect position or count',mtconfirmation,[],0)
        else begin
           if pos>size then begin
              pos := size;
              uncorrect := true;
           end;
           while ((pos + count -1) > size) do
                 count := count - 1;
           //
           closefile(f);
           rename(f,'Data_base_edit.txt');
           reset(f);
           Assignfile(Vrem,'Data_base.txt');
           rewrite(Vrem);
           vsp := pos -1;
           for i:=1 to vsp do begin
               read(f,rec);
               write(Vrem,rec);
           end;
           for i:=1 to count do read(f,rec);
           vsp := size - pos - count +1;
           for i:=1 to vsp do begin
               read(f,rec);
               write(Vrem,rec);
           end;
           closefile(Vrem);
           closefile(f);
           erase(f);
           Assignfile(f,'Data_base.txt');
           Reset(f);
           seek(f,filesize(f));
           str(filesize(f),s); edit6.text:=s; edit5.text:=s;
           str(count,s); edit7.text:=s;
           if uncorrect then
              s:='Position was > then filesize, was delete last el'
           else
               s := 'Successfull!';
           messagedlg(s,mtconfirmation,[],0);
        end;
     end
     else messagedlg('File was empty ',mtconfirmation,[],0)
end;

procedure TAccess.Button9Click(Sender: TObject);
var s:string;
begin
     edit1.Enabled:=false;
     edit2.Enabled:=false;
     edit3.Enabled:=false;
     edit4.Enabled:=false;
     edit5.Enabled:=false;
     edit6.Enabled:=false;
     edit7.Enabled:=false;
     Button5.Enabled:=false;
     Button6.Enabled:=false;
     Button7.Enabled:=false;
     Button8.Enabled:=false;
     Button9.Enabled:=false;
     button1.enabled:=true;
     button2.enabled:=true;
     if IOresult=0 then begin
       str(filesize(f),s); edit6.text:=s; edit5.text:=s;
     end
     else begin
       edit6.text:='0'; edit5.text:='0';
     end;
end;

procedure TAccess.FormShow(Sender: TObject);
var s:string;
begin
     edit1.Enabled:=false;
     edit2.Enabled:=false;
     edit3.Enabled:=false;
     edit4.Enabled:=false;
     edit5.Enabled:=false;
     edit6.Enabled:=false;
     edit7.Enabled:=false;
     button1.enabled:=true;
     button2.enabled:=true;
     Button5.Enabled:=false;
     Button6.Enabled:=false;
     Button7.Enabled:=false;
     Button8.Enabled:=false;
     Button9.Enabled:=false;
     assignfile(f,'Data_base.txt');
     {$I-}  reset(f); {$I+}
     if Ioresult=0 then begin
       seek(f,filesize(f));
       str(filesize(f),s); edit6.text:=s; edit5.text:=s;
     end
     else begin
       rewrite(f);
       edit6.text:='0'; edit5.text:='0';
     end;
end;


procedure TAccess.Button2Click(Sender: TObject);
begin
     button1.enabled :=false;
     button2.enabled:=false;
     edit6.enabled:=true;
     edit7.enabled:=true;
     Button8.Enabled:=true;
     Button9.Enabled:=true;
end;

procedure TAccess.Button3Click(Sender: TObject);
var key:boolean=false;
begin
     if (filesize(f)=0)then messagedlg('File was empty ',mtconfirmation,[],0)
     else begin
          key:=Messagedlg('WARNING! Will be deleted ALL data-base, Are you sure?', mtConfirmation,mbYesNo,0)=mrYes;
          if key then begin
             rewrite(f);
             edit6.text:='0'; edit5.text:='0';
          end;
     end;
end;

procedure TAccess.Button1Click(Sender: TObject);
begin
     button1.enabled :=false;
     button2.enabled:=false;
     edit1.Enabled:=true;
     edit2.Enabled:=true;
     edit3.Enabled:=true;
     edit4.Enabled:=true;
     Button5.Enabled:=true;
     Button6.Enabled:=true;
     Button9.Enabled:=true;
end;

procedure TAccess.Button10Click(Sender: TObject);
var rec : metro_member;
  size,i:integer;
begin
     stringgrid1.Clean();
     reset(f);
     stringgrid1.Cells[0,0]:= '№';
     stringgrid1.cells[1,0]:='Inventory number';
     stringgrid1.cells[2,0]:='Model';
     stringgrid1.cells[3,0]:='Year';
     stringgrid1.cells[4,0]:='Life time';
     size := filesize(f);
     for i:= 1 to size do begin
       read(f,rec);
       stringgrid1.cells[0,i]:=inttostr(i);
       stringgrid1.cells[1,i]:=inttostr(rec.Inv_num);
       stringgrid1.cells[2,i]:=rec.model;
       stringgrid1.cells[3,i]:=inttostr(rec.birthday);
       stringgrid1.cells[4,i]:=inttostr(rec.life_time);
     end;
end;

end.


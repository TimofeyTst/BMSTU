unit Data_base_form;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls,
  Graphics, Dialogs, StdCtrls, Grids, ComCtrls,graphic_form;

type

  { TData_base }

  TData_base = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Edit1Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure FormShow(Sender: TObject);
  private

  public

  end;

var
  Data_base: TData_base;

implementation
uses main_form;
var kod:integer;
{$R *.lfm}

{ TData_base }

procedure TData_base.Button6Click(Sender: TObject);
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

procedure TData_base.Button7Click(Sender: TObject);
var rec:metro_member;
i,vsp,j:integer;
s:string;
begin
     reset(f);
     stringgrid1.Clean(1,1,4,1000,[]);
     case kod of
     1:begin
       val(edit1.Text,vsp,i);
       j:=1;
       for i:=1 to filesize(f) do begin
           read(f,rec);
           if rec.birthday >= vsp then begin
              stringgrid1.cells[0,j]:=inttostr(j);
              stringgrid1.cells[1,j]:=inttostr(rec.Inv_num);
              stringgrid1.cells[2,j]:=rec.model;
              stringgrid1.cells[3,j]:=inttostr(rec.birthday);
              stringgrid1.cells[4,j]:=inttostr(rec.life_time);
              j:=j+1;
           end;
       end;
       s:=inttostr(j-1);
       edit2.text:='Total: '+s;
       end;
     2:begin
            s:=edit1.text;
            j:=1;
            for i:=1 to filesize(f) do begin
                read(f,rec);
                if rec.model = s then begin
                     stringgrid1.cells[0,j]:=inttostr(j);
                     stringgrid1.cells[1,j]:=inttostr(rec.Inv_num);
                     stringgrid1.cells[2,j]:=rec.model;
                     stringgrid1.cells[3,j]:=inttostr(rec.birthday);
                     stringgrid1.cells[4,j]:=inttostr(rec.life_time);
                     j:=j+ 1;
                end;
            end;
            s:=inttostr(j-1);
            edit2.text:='Total: '+s;
       end;
     3: begin
             val(edit1.text,vsp,i);
             j:=1;
             for i:=1 to filesize(f) do begin
                 read(f,rec);
                 if (rec.birthday+rec.life_time) < vsp then begin
                     stringgrid1.cells[0,j]:=inttostr(j);
                     stringgrid1.cells[1,j]:=inttostr(rec.Inv_num);
                     stringgrid1.cells[2,j]:=rec.model;
                     stringgrid1.cells[3,j]:=inttostr(rec.birthday);
                     stringgrid1.cells[4,j]:=inttostr(rec.life_time);
                     j:=j+ 1;
                 end;
             end;
             s:=inttostr(j-1);
             edit2.text:='Total: '+s;
         end;
     end;
      edit1.Enabled:=false;
      button7.enabled:=false;
      button1.Enabled:=True;
      button2.Enabled:=true;
      button3.Enabled:=true;
      button4.Enabled:=true;
end;


procedure TData_base.Edit1Click(Sender: TObject);
begin
     edit1.Clear;
end;

procedure TData_base.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
     graphic_trams.Close;
end;

procedure TData_base.FormShow(Sender: TObject);
begin
      assignfile(f,'Data_base.txt');
     {$I-}  reset(f); {$I+}
     if Ioresult<>0 then begin
     messagedlg('Data is empty ',mtconfirmation,[],0);
     data_base.Close;
     main.Show;
     end
     else begin
         edit2.Clear;
         edit2.ReadOnly:=true;
          edit1.Enabled:=false;
          button7.enabled:=false;
           button1.Enabled:=True;
           button2.Enabled:=true;
           button3.Enabled:=true;
           button4.Enabled:=true;
     end;
end;

procedure TData_base.Button5Click(Sender: TObject);
begin
     data_base.close;
     main.Show;
     closefile(f);
end;

procedure TData_base.Button1Click(Sender: TObject);
begin
     edit2.Clear;
     edit1.text:='Year:';
     button1.Enabled:=false;
     button2.Enabled:=false;
     button3.Enabled:=false;
     button4.Enabled:=false;
     edit1.Enabled:=True;
     button7.enabled:=true;
     kod :=1;
     edit1.NumbersOnly:=true;
end;

procedure TData_base.Button2Click(Sender: TObject);
begin
     edit2.Clear;
     edit1.text:='Model:';
     button1.Enabled:=false;
     button2.Enabled:=false;
     button3.Enabled:=false;
     button4.Enabled:=false;
     edit1.Enabled:=true;
     button7.enabled:=true;
     kod :=2;
     edit1.NumbersOnly:=false;
end;

procedure TData_base.Button3Click(Sender: TObject);
begin
     button3.Enabled:=false;
     graphic_trams.Show;
end;

procedure TData_base.Button4Click(Sender: TObject);
begin
      edit2.Clear;
      edit1.text:='Year now:';
      button1.Enabled:=false;
      button2.Enabled:=false;
      button3.Enabled:=false;
      button4.Enabled:=false;
      edit1.Enabled:=true;
      button7.enabled:=true;
      kod :=3;
      edit1.NumbersOnly:=false;
end;

end.


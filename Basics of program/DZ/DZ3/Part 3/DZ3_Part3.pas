program DZ3_Part3;
  Type mas=array [1..10] of string;
  Type slovo=object
       private sod:string;
       procedure init(isod:string);
       procedure Print();
       function Dlina:integer;
       function I:boolean;
  end;
  Type predlozheniye=object
        private k:integer;
        private sod:array [1..10] of slovo;
        procedure Init(ik:integer;isod:mas);
        procedure Print();
        function Dlina:integer;
        function IK:integer;
  end;



   procedure Slovo.init(isod:string);
   begin
        sod:=isod;
   end;
   procedure Slovo.print;
   begin
        write(sod);
   end;
   function Slovo.dlina:integer;
   begin
        result:=length(sod);
   end;
   function slovo.I:boolean;
   begin
        if (ord(sod[1])>64) and (ord(sod[1])<91) then result:=True
        else result:=false;
   end;
   procedure Predlozheniye.Init(ik:integer;isod:mas);
   var
     i:integer;
   begin
        i:=1;
        k:=ik;
        for i:=1 to ik do
        sod[i].init(isod[i]);
   end;
   procedure Predlozheniye.print;
   var i:integer;
   begin
        for i:=1 to k do begin
        sod[i].print;
        write(' ');
        end;
   end;
   function predlozheniye.dlina:integer;
   var i,res:integer;
   begin
        res:=0;
        for i:=1 to k do
        res:=res+sod[i].dlina;
        result:=res;
   end;
   function predlozheniye.IK:integer;
   var i,res:integer;
   begin
        res:=0;
        for i:=1 to k do
        if sod[i].I then res:=res+1;
        result:=res;
   end;
var vvod:mas;
    s:string;
    i:integer;
    Conduct:predlozheniye;
begin
     i:=1;
     writeln('Input strings, "/" for end: ');
     write(i,') ');
     readln(s);
     while (s<>'/') and (i<11) do begin
       vvod[i]:=s;
       i:=i+1;
       write(i,') ');
       readln(s);
       end;
     Conduct.init(i-1,vvod);
     Conduct.Print;
     writeln;
     writeln('Dlina predlozheniya: ',Conduct.dlina,' symbols');
     writeln('Kol-vo imen sobstvennih: ',Conduct.ik);

     readln;
end.


program Pt3_MyEdition;
   Type pstr=^str;
         str=record
         t:string;
         next:pstr;
         end;
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
        procedure Init(ik:integer;isod:pstr);
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
   procedure Predlozheniye.Init(ik:integer;isod:pstr);
   var i:integer;
   begin
         if ik>10 then begin
                       writeln('Error: length<=10!');
                       exit;
                       end
         else begin
              k:=ik;
              for i:=1 to ik do begin
                                sod[i].init(isod^.t);
                                isod:=isod^.next;
                                end;
              end;
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
var vvod,q:pstr;
    i:integer;
    s:string;
    Conduct:predlozheniye;
begin
     writeln('Menu: "/" for end input');
     i:=1;
     write(i,')');
     readln(s);
     vvod:=nil;
     if s<>'/' then begin
                   new(vvod);
                   vvod^.t:=s;
                   vvod^.next:=nil;
                   i:=i+1;
                   write(i,')');
                   readln(s);
                   q:=vvod;
                   while s<>'/' do begin
                                   new(q^.next);
                                   q:=q^.next;
                                   q^.t:=s;
                                   q^.next:=nil;
                                   i:=i+1;
                                   write(i,')');
                                   readln(s);
                                   end;
                    end;

     Conduct.init(i-1,vvod);
     //Освободим память
     while vvod<>nil do begin
                q:=vvod;
                vvod:=vvod^.next;
                dispose(q);
                i:=i-1;
     end;
     if i-1=0 then writeln('Memory free: Successfully!') else writeln('Memory free: Error!');


     Conduct.Print;
     writeln;
     writeln('Dlina predlozheniya: ',Conduct.dlina,' symbols');
     writeln('Kol-vo imen sobstvennih: ',Conduct.ik);
     readln;
end.


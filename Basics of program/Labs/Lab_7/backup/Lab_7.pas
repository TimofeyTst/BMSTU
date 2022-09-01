program Lab_7;
 function IF7(s:string):boolean;
var
    i:word;
    key:boolean;
begin
i:=1;
result:=false;
key:=true;
while (i<=length(s)) and key do
  begin
       if s[i]='7' then
       begin
         result:=true;
         key:=false;
       end;
       i:=i+1;
  end;
end;

var
    m:array of word;
    n,i,k4:integer;
    s:string;
begin
  writeln('Input n: ');
  readln(n);
  setlength(m,n);
  Randomize;
  k4:=0;
  for i:=0 to n-1 do
      begin
      m[i]:=random(65536);
      writeln(i+1,')',m[i]);
      str(m[i],s);
      if IF7(s) then
         k4:=k4+1;
      end;
//Определить кол-во чисел, в десятичной записи которых есть '7'

   writeln('Kol-vo elementov soderzhashihsa " 7 ": ',k4);
   readln
end.


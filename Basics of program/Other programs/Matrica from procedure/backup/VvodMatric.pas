program VvodMatric;

uses Unit1;

type tim = array [1..3,'A'..'C'] of integer;
procedure vvod(var T:tim);
var s:char; i1,i2:integer;
begin
  s:='A';
  i1:=1;
  i2:=1;
for i1:=1 to 3 do
begin
  writeln(i1,' stroka');
                   for i2:=1 to 3 do
                   begin
                       write(' ');
                       readln(T[i1,s]);
                       s:=succ(s);
                   end;
  s:='A';
end;
end;
procedure vivod(var T:tim; N:integer);
function opr(M:tim; gl,pob:integer):integer;
begin
gl:=M[1,'A']*M[2,'B']*M[3,'C']+M[1,'B']*M[2,'C']*M[3,'A']+M[1,'C']*M[2,'A']*M[3,'B'];
pob:=M[1,'C']*M[2,'B']*M[3,'A']+M[1,'A']*M[2,'C']*M[3,'B']+M[1,'B']*M[2,'A']*M[3,'C'];
opr:=gl-pob;
end;

var s:char; i1,i2:integer;
begin
s:='A';
writeln('Poly4im matricy ',N, ')');
    for i1:=1 to 3 do
  begin
                  for i2:=1 to 3 do
                  begin
                      write(' ');
                      write (T[i1,s],' ');
                      s:=succ(s);
                  end;
                  writeln;
                  s:='A';
  end;
end;
var T,Y,L:tim; r:integer;
begin
Writeln('VVOD Trex matric');
        write('1)');
vvod(T);
vivod(T,1);
writeln(r);
readln
end.


program Text_kak_tip;
var T:text;
sml:char;
name,s:string;

begin
  Writeln('Input file name: ');
  readln(name);
  assign(t,name+'.txt');
  reset(t);
  s:='';
  while not eof(t) do
  begin
  while (sml<>'#13') and not eof(t) do
  begin
       read(t,sml);
       s:=s+sml;
       writeln(s);
  end;
  if not eof(t) then read(t,sml);
  end;
  readln;

end.


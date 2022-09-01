program Pervy_file;
var f:file of char;
  s:string;
  sbl:char;
  i,n:integer;
begin
  randomize;
  writeln('File name: ');
  readln(s);
  Assignfile(f,s);
  rewrite(f);
  writeln('Input symbol or #: ');
  readln(sbl);
  while sbl<>'#' do
  begin
  write(f,sbl);
  readln(sbl);
  end;

  Reset(f);
  while not EOF(f) do
  begin
  Read(f,sbl);
  writeln(sbl);
  end;

  i:=1;
  reset(f);
  while not EOF(f) do
  begin
       Write(i,' Symbol zamenyaem na ');
       readln(sbl);
       Write(f,sbl);
       i:=i+1;
  end;

    Reset(f);
  while not EOF(f) do
  begin
  Read(f,sbl);
  writeln(sbl);
  end;
    readln;
end.


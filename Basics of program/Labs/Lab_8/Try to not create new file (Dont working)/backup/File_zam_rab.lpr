program File_zam_rab;
var
   T:text;
   name,zam:string;
   i,k:integer;
begin
  write('Input name of File: ');
  readln(name);
  Assign(T,name+'.txt');
  {$I-}
  Reset(t);
  {$I+}
  if IOresult<>0 then
  begin
       Writeln('Error: Write correctly name of File!');
       Halt;
       readln;
  end;
  Write('Input number of string will be replace: ');
  readln(k);
  write('Input your predlozheniye: ');
  readln(zam);
  i:=1;
  while not eof(t) do
  begin
       read(t);
       if i=k+1 then
       write(t,zam);
       i:=i+1;
  end;
  closefile(t);
  readln
end.


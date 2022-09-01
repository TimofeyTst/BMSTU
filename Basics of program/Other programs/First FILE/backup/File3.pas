program File3;
var f:file of char;
  i,k,j:integer;
  sbl:char;
  s:string;
begin
  writeln('Input File name: ');
  readln(s);
  Assign(f,s);
  Reset(f);
  j:=0;
For i:=1 to filesize(f) do
       begin
       Read(f,sbl);
       if i mod 2 <> 0 then
       begin

            k:=filepos(f);
            seek(f,j);
            write(f,sbl);
            seek(f,k);
            j:=j+1;
       end;
       end;
       seek(f,j);
       truncate(f);
   reset(f);
   while not EOF(f) do
        begin
        Read(f,sbl);
        write(sbl,' ');
        end;
   readln;
end.


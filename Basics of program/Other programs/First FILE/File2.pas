program File2;
type
  mnoj=set of char;
  ch=file of mnoj;
var f:file of char;
  i:integer;
  s:string;
  h:char;
  procedure su(var f:ch);
  begin
       write(f,'a');
       reset(f);
       read(f,h);
       writeln(h);
       readln;
  end;

begin
  writeln('Name of file: ');
  readln(s);
  Assign(f,s);
  Rewrite(f);
  su(f);
  writeln(filesize(f));
  i:=0;
  while i<=(filesize(f)/2) do
  begin;
        writeln;
        writeln('Size= ',filesize(f));
        writeln('Pos= ',filepos(f));
        writeln('Symbols: ');
        Read(f,h);
        write(h);
        seek(f,filesize(f)-filepos(f));
        Read(f,h);
        write(h);
        i:=i+1;
        seek(f,i);
  end;
  readln;
end.


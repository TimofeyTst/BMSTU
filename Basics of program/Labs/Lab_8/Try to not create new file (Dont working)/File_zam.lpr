program File_zam;

var
  f:text;
  name,s:string;
  i:integer;
begin
      write('Input name of file: ');
      readln(name);
      assign(f,name+'.txt');
      rewrite(f);
      i:=1;
      write(i,') String in file: ');
      readln(s);
      while s<>'#' do
            begin
              Writeln(f,s);
              i:=i+1;
              write(i,') String in file: ');
              readln(s);
            end;
      closefile(f);
      readln
end.


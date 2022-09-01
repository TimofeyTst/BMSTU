program Rabota_s_file;
  uses sysutils;
var
  f:text;
  name,s:string;
  i:real;
begin
name:='Testirovshik';
      assign(f,name+'.txt');
      //
        i:=diskfree(3)/(1024*1024*1024);
        s:=changefileext(f,'.bak');
      //
      writeln('disk= ',i:4:5);
      writeln('stroka s= ',s);
      readln
end.


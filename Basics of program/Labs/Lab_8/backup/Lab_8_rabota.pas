program Lab_8_rabota;
//Сделал универсальным программу, создавая при необх файл
  procedure SozdFile(name:string);
  var
  f:text;
  s:string;
  i:integer;
  begin
      assign(f,name+'.txt');
      rewrite(f);
      i:=1;
      writeln('!!When end of file write "#"!!');
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
  end;

var
  f,b:text;
  i,k:integer;
  s,zam,name:string;
  key:boolean;
begin
      writeln('If you want to crate a new file write "Create", or write "No":');
      readln(s);
      if (s='create') or (s='Create') then
           begin
             write('Input name of will be created file: ');
             readln(name);
             sozdfile(name);
           end
      else begin
             write('Input name of existing file: ');
             readln(name);
             assign(b,name+'.txt');
             {$I-}
              reset(b);
             {$I+}
             if IOresult<>0 then begin
                                 writeln('ERROR: File wasn`t found, write correctly name!');
                                 halt;
                                 writeln;;
                                 readln;
                                 end;
             closefile(b);
             end;
      //Либо файл существует, либо создали новый
      //Далее копируем файл, сохраняя имя и заменяя строку
      assign(b,name+'.txt');
      rename(b,'delete.txt');
      reset(b);
      assign(f,name+'.txt');
      rewrite(f);
      i:=0;
      write('Nomer zamenyemoy stroki: ');
      readln(k);
      write('Zamenyem na: ');
      readln(zam);
      while not eof(b) do
      begin
           readln(b,s);
           if i=k then
           begin
           writeln(f,zam);
           readln(b);
           end
           else writeln(f,s);
           i:=i+1;
      end;
      closefile(f);
      closefile(b);
      erase(b);
      writeln('Succsesfuly!');
      readln
end.


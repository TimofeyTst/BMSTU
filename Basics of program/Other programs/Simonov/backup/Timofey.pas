program Timofey;

type book = record
     name:string[20];
     author:string[20];
     year:integer;
end;

var f,fo : file of book;
b: book;
k:string[20];


begin
  assign(f,'knigi.txt');
  rewrite(f);
  write('Input name of book or "n": ');
  readln(k);
  while (k<>'n') and (k<>'N') do
  begin
    b.name:=k;
    write('Input name of author:');
    readln(b.author);
    write('Year:');
    readln(b.year);
    write(f,b);
    write('Input name of book or "n": ');
    readln(k);
  end;

  closefile(f);
  //Создали файл

  Writeln('Input name of will be deleted author');
  Readln(k);

  Reset(f);
  assign(fo,'temp.txt');
  rewrite(fo);
  //
  while not eof(f) do
  begin
    read(f,b);
    if b.author<>k then
    write(fo,b);
  end;

  closefile(f);
  closefile(fo);
  erase(f);
  rename(fo,'knigi.txt');

  Writeln('Successfuly!');
  Readln;
end.

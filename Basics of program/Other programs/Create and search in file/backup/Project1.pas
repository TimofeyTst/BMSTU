program Fylik_sozd;
type
    birthday=record
    year:integer;
    month,day:byte;
    end;
    personage=record
    fam:string[40];
    date:birthday;
    end;

var fylik:file of personage;
    Persona:personage;
    s:string[40];
    i:integer;
begin
  writeln('Input File name: ');
  readln(s);
  Assign(fylik,s);
  Rewrite(fylik);
  i:=1;
  persona.fam:='';
  Write('Input FIO of ',i,' Person: ');
       Readln(Persona.fam);
  while persona.fam<>'#' do
       begin
       write('Input her/his birthday format day, month, year: ');
       readln(persona.date.day, persona.date.month, persona.date.year);
       write(fylik,persona);
       writeln;
       Write('Input FIO of ',i,' Person: ');
       Read(Persona.fam);
       end;
  reset(fylik);
   closefile(fylik);
  readln;
end.


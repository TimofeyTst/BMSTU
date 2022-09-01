program Fylik_poiska;
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
    Persona,poisk:personage;
    s:string;
    key:boolean;
begin
  writeln('Input File name: ');
  readln(s);
  Assign(fylik,s);
  Reset(fylik);
  writeln('Input poisk fam: ');
  readln(poisk.fam);
  key:=false;
  while not key and not EOF(fylik) do
  begin
  read(fylik,persona);
  if persona.fam=poisk.fam then
  begin
        poisk.date:=persona.date;
        writeln('Date of his/her birthday: ');
        writeln(persona.date.day,' ', persona.date.month,' ', persona.date.year);
        key:=true;
  end;
  end;
  if not key then writeln ('Name wasnt found ');
   readln;
end.

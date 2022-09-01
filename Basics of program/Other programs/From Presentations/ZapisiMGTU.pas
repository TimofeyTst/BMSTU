program ZapisiMGTU;
Type
  data=record
    year:word;
    month:1..12;
    day:1..31;
  end;
  zap=record
    fam:string[16];
    birthday:data;
  end;
var
   fb:array [1..25] of zap;
   fam:string[16];
   n,i:integer;
   key:boolean;
begin
    i:=0;
    write('Dlina massiva: ');
    readln(n);
        repeat
          i:=i+1;
          write ('Familia: ');
          readln (fb[i].fam);
          write ('Day: ');
          readln (fb[i].birthday.day);
          write ('Month: ');
          readln (fb[i].birthday.month);
          write ('Year: ');
          readln (fb[i].birthday.year);
        until i=n ;
 for i:=1 to n do
     with fb[i] do
          begin
            write(i,') ',fam);
            with birthday do
                 begin
                   writeln (' ',day,' ',month,' ',year);
                 end;
          end;
 writeln('Familiu to vvedi nakonec: ');
 readln (fam);
 key:=false;
  for i:=1 to n do
      if (fb[i].fam=fam) then
         with fb[i] do
              begin
              key:=true;
              write (i,') ', fam);
              with birthday do
                   write (' den ',day,' Mesac ',month, ' year ',year);
              end;
  if not key then writeln('Pizdec');
 readln
end.


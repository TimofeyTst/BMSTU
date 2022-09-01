program Matrica_kn;
Type min=record
     el,ind:integer;
     end;
  mass=array of array of integer;
  procedure zapomnit(const i,c,n:integer; matrica:mass; var min:min);
  begin
       min.el:=matrica[i,c];
       min.ind:=i*n+c+1;
  end;
  procedure zapolnit(const n:integer; var matrica:mass);
  var i,c:integer;
  begin
       randomize;
       for i:=0 to n-1 do
       begin
            writeln;
            for c:=0 to n-1 do
            begin
                 matrica[i,c]:=random(n+n);
                 write(matrica[i,c],' ');
            end;
       end;
  writeln;
  end;

var matrica:mass;
  i,c,n,k,key:integer;
  min1,min2:min;
begin
  write('Input size of matric N: ');
  readln(n);
  write('Input k: ');
  readln(k);

  Setlength(matrica,n,n);
  zapolnit(n,matrica);
  key:=0;
  min1.el:=matrica[0,0];
  min1.ind:=1;
  min2.el:=matrica[0,k];
  min2.ind:=k;
  //Поиск в верхней левой части минимального элемента
  for i:=0 to k-1 do
      begin
      writeln;
      for c:=0 to k-i-1 do
          begin
               if min1.el>matrica[i,c] then
                  zapomnit(i,c,n,matrica,min1);
               write(matrica[i,c],' ');
          end;
      end;
  writeln;
  //Поиск в нижней правой части минимального элемента
  for i:=0 to n-1 do
      begin
      writeln;
      if i>k then
         key:=key+1;
      for c:=k-i+key to n-1 do
          begin
               if min2.el>matrica[i,c] then
                  Zapomnit(i,c,n,matrica,min2);
               write(matrica[i,c],' ');
          end;
      end;
  //Далее вывод
      writeln;
      writeln('Minimalniy element verhney levoy chasti: ',min1.el);
      writeln('Ego nomer: ',min1.ind);
      writeln('Minimalniy element nizhney pravoy chasti: ',min2.el);
      writeln('Ego nomer: ',min2.ind);

  readln
end.


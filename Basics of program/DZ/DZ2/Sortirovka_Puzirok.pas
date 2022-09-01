program Sortirovka_Puzirok;

var
  T: array [1..30] of integer;
  i,k,n:integer;
begin
  write('n = ');
  readln(n);
  randomize;
  for i:=1 to n do
      T[i]:= random(30)+1;
  for i:=1 to n do write('T[',i,']= ', T[i],' ');
//Заполнил и вывел массив
  for i:=1 to n-1 do
      for k:=1 to n-i do
          if T[k+1]<T[k] then
          begin   //Меняем местами без третьей переменной
            T[k]:=T[k+1]+T[k];
            T[k+1]:=T[k]-T[k+1];
            T[k]:=T[k]-T[k+1];
          end;
  writeln;
  WRITELN('Otsortiroval:');
  for i:=1 to n do write('T[',i,']= ', T[i],' ');
  readln
end.


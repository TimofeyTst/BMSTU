program sinus;
Uses math;
 var M:array [1..50] of real; k,n:integer; x:real; t:boolean;
begin
  write('x= ');
  readln(x);
  k:=0;
  //Задаю массив
  for n:=1 to 50 do
      M[n]:=sin(power(x,n));
  //Для наглядности выведу массив
  writeln('Zna4eniya sinusa:');
  for n:=1 to 50 do
      write(M[n]:5:20, ' ');
  //Счет отрицательных чисел в массиве
  for n:=1 to 50 do
     begin
         if M[n]<0 then
         k:=k+1
     end;
  if k>3 then
     t:=true
  else t:=false;
  writeln;
  writeln('T = ',t, '    Tak kak otricatelnix 4isel = ', k);
  readln
end.


program Matrica_0;
Type
  element=record
    i,j:integer;
  end;

var
  A:array [1..8,1..15] of integer;
  i,j,n,m:integer;
  max,min,raznost:element;
  key:boolean;
begin
     writeln ('Matrica n*m');
     write ('n = ');
     readln(n);
     write ('m = ');
     readln(m);
     randomize;
     for i:=1 to n do
        begin
        writeln;
         for j:=1 to m do
             begin
             A[i,j]:=random(5);
             write (A[i,j],' ');
             end;
        end;
     //Выведем матрицу
     writeln;
     //Проверка на ненулевую
     key:=false;
     for i:=1 to n do
         for j:=1 to m do
             if not key and (A[i,j]<>0) then
             begin
               key:=true;
               max.i:=i;
               max.j:=j;
               min.i:=i;
               min.j:=j;
             end;

     //Ищем макс и мин элемент
     if key then
     begin
     for i:=1 to n do
         for j:=1 to m do
             if (A[i,j]<>0) then
             begin
               if A[i,j]>A[max.i,max.j] then
               begin
                 max.i:=i;
                 max.j:=j
               end;
                if A[i,j]<A[min.i,min.j] then
               begin
                 min.i:=i;
                 min.j:=j
               end;
             end;
     raznost.i:=max.i-min.i;
     raznost.j:=max.j-min.j;
     writeln('Raznost indexov max i min elementov = ',raznost.i,' ',raznost.j);
     writeln('Max element = ', A[max.i,max.j], ' Min element = ',A[min.i,min.j]);
     end
     else writeln ('Matrica soderzhit tolko nyli');
     readln
end.


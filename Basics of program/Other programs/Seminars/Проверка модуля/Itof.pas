program Itof;
uses tstek;
{Из списка типа стек последний элемент записать на место
первого. Последний удалить. Сделать для двусвязного и односвязного
списка}
var
    firs1,q1:point_1s;
    firs2,q2:point_2s;
    c:integer;
begin
     writeln('Input "1" for odnosvyaznogo or "2" for 2-svyaznogo or any number for end program');
     readln(c);
     if c=1 then begin
     create(firs1,c,s1);
     //Вывод
     q1:=firs1;
     while q1<>nil do
           begin
                write(q1^.s);
                q1:=q1^.next;
           end;
           writeln;
     //Выполнение задачи
     writeln('1=posled, posled will be deleted');
     omogus(firs1,s1);
     c:=c-1;
     //Проверка выводом
     q1:=firs1;
     while q1<>nil do
           begin
                write(q1^.s);
                q1:=q1^.next;
           end;
           writeln;
     //Освобождение памяти
     writeln('Points in memory: ',c ,' Enter to dispose memory');
     readln;
     clear(firs1,c,s1);
     end;
     if c=2 then begin
     create(firs2,c,s2);
     //Вывод
     q2:=firs2;
     while q2<>nil do
           begin
                write(q2^.s);
                q2:=q2^.next;
           end;
           writeln;
     //Выполнение задачи
     writeln('1=posled, posled will be deleted');
     omogus(firs2,s2);
     c:=c-1;
     //Проверка выводом
     q2:=firs2;
     while q2<>nil do
           begin
                write(q2^.s);
                q2:=q2^.next;
           end;
           writeln;
     //Освобождение памяти
     writeln('Points in memory: ',c ,' Enter to dispose memory');
     readln;
     clear(firs2,c,s2);
     end;
     readln;
end.


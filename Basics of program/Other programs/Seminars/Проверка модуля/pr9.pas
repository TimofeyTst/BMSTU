program pr9;
uses tstek;
{Из списка типа стек последний элемент записать на место
первого. Последний удалить. Сделать для двусвязного и односвязного
списка}
var
    firs1,q1:point_1s;
    c:integer;
begin
     create(firs1,c,s1);
     //Вывод
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
     readln;
end.


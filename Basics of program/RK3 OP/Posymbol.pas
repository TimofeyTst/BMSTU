program Posymbol;
Type point=^el;
  el=record
    symb:char;
    next:point;
    prev:point;
  end;
  procedure continue(var q:point;var symb:char);
  begin
       write('Input: ');
       readln(symb);
       if symb='/' then begin
                   dispose(q);
                   Writeln('Your list is empty');
                   readln;
                   Halt;
                   end
       else if symb='#' then begin
                        writeln('Error: string is empty, write smth!');
                        continue(q,symb);
                        end
            else q^.symb:=symb;
  end;

  var symb:char;
      first,q,v:point;
begin
     first:=nil;
     writeln('Menu: "/" - for end of vvod, "#" - for delete last written symbol');
     writeln;
     write('Input: ');
     readln(symb);
     while symb='#' do begin
                       writeln('Error: string is empty, write smth!');
                       write('Input: ');
                       readln(symb);
                       end;

     if symb<>'/' then
     begin
     new(first);
     first^.symb:=symb;
     first^.prev:=nil;
     first^.next:=nil;
     q:=first;
     write('Input: ');
     readln(symb);
     while symb<>'/' do
                     begin
                     if symb<>'#' then begin
                                  new(q^.next);
                                  q^.next^.prev:=q;
                                  q:=q^.next;
                                  q^.symb:=symb;
                                  q^.next:=nil;
                                  end
                     else if q<>first then begin
                                      q:=q^.prev;
                                      dispose(q^.next);
                                      q^.next:=nil;
                                      end
                          else continue(first,symb);
                     write('Input: ');
                     readln(symb);
                     end;
     //Выведем
     v:=first;
     while v<>nil do
     begin
          write(v^.symb);
          v:=v^.next;
     end;
     //Удалим все, кроме последнего
     v:=first^.next;
     while v<>nil do
     begin
          dispose(v^.prev);
          q:=v; //Запоминаем последний
          v:=v^.next;
     end;
     dispose(q);
     writeln;

     writeln('Memory dispose: Successfully!');
     end;
     readln;
end.


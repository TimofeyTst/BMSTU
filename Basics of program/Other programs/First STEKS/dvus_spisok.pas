program dvus_spisok;
Type pointer=^element;
  element=record
     s:string;
     next:pointer;
     prev:pointer;
     end;
  var first,q,v:pointer;
      s:string;
      Num:integer;
begin
     writeln('Enter to begin');
     readln;
     new(first);
     write('Input s or "end": ');
     readln(S);
     if s<>'end' then
     begin
     first^.s:=s;
     first^.prev:=nil;
     first^.next:=nil;
     write('Input s or "end": ');
     readln(S);
     q:=first;
     while s<>'end' do
           begin
                new(q^.next);
                q^.next^.s:=s;
                q^.next^.prev:=q;
                q^.next^.next:=nil;
                q:=q^.next;
                write('Input s or "end": ');
                readln(S);
           end;
     end;

     Writeln('Enter to view spisok ');
     readln;
     Writeln('First into last: ');
     v:=first;
     while v<>nil do
     begin
          writeln(v^.s);
          v:=v^.next;
     end;
     writeln('Last into first: ');
     v:=q;
     while v<>nil do
     begin
          writeln(v^.s);
          v:=v^.prev;
     end;

     readln;
end.


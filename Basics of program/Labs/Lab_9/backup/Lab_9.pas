program Lab_9;
Type pointer=^element;
     element=record
             num:real;
             next:pointer;
             prev:pointer;
             end;
     procedure max(x1,x2:real);
     begin
          if x1>=x2 then write(x1:3:1,' ')
          else write(x2:3:1,' ');
     end;
     procedure create_2s(var first,q:pointer);
     var s:string[8];
     code:integer;
     begin
          write('Input number or "end": ');
          readln(s);
     if s<>'end' then
     begin
          new(first);
          val(s,first^.num,code);
          first^.next:=nil;
          first^.prev:=nil;
          q:=first;
          write('Input number or "end": ');
          readln(s);
          while s<>'end' do
                begin
                new(q^.next);
                val(s,q^.next^.num,code);
                q^.next^.prev:=q;
                q^.next^.next:=nil;
                q:=q^.next;
                write('Input number or "end": ');
                readln(s);
                end;
     end
     else begin
       first:=nil;
       q:=first;
       writeln('List is empty');
       readln;
       halt;
       end;
     end;

var first,q,rab:pointer;
begin
     writeln('Enter to begin');
     readln;
     create_2s(first,q);
     rab:=first;
     while rab<>nil do
           begin
                max(rab^.num,q^.num);
                rab:=rab^.next;
                dispose(rab^.prev);
                q:=q^.prev;
                dispose (q^.next);
           end;
     readln;
end.


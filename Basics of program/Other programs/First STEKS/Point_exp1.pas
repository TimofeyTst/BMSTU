program Point_exp1;
Type ykaz=^el;
  el=record
    n:string;
    next:ykaz;
    end;
  var first:ykaz;
begin
     new(first);
     first^.n:='First string';
     new(first^.next);
     first^.next^.n:='second string';
     //first^.next^.next:=nil;
     writeln('Enter to Vivod:');
     readln;
     writeln(first^.n);
     writeln(first^.next^.n);
     writeln('Enter to dispose vivod:');
     readln;
     dispose(first);

     writeln(first^.n);
     readln;

end.


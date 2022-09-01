program Derevce;
type pointik=^el;
  el=record
  s:integer;
    left,right:pointik;
 end;
  var
  i:integer;
  coin:integer;
  derevo:pointik;
  procedure Form_tree(var derevo:pointik; ch:integer);

  begin
       if derevo<>nil then
                      if ch>=derevo^.s then
                      Form_tree(derevo^.right,ch)
                      else Form_tree(Derevo^.left,ch)
       else begin
                 new(derevo);
                 coin:=coin+1;
                 derevo^.s:=ch;
                 derevo^.right:=nil;
                 derevo^.left:=nil;
            end;
  end;
  procedure view_tree(var derevo:pointik);
  begin
       if derevo<>nil then begin
         view_tree(derevo^.left);
         write(derevo^.s);
         view_tree(derevo^.right);
         dispose(derevo);
         coin:=coin-1;
         end;
  end;
begin
    randomize;
    new(derevo);
    coin:=1;
    derevo^.s:=5;
    derevo^.left:=nil;
    derevo^.right:=nil;
    write('Input 4islo: ');
    readln(i);
    while i<>0 do begin
          form_tree(derevo,i);
          write('Input 4islo: ');
          readln(i);
          end;
    view_tree(derevo);
    writeln('Coin= ',coin);
    readln;

end.


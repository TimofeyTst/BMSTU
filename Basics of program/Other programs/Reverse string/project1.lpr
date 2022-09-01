program project1;
function rev(var st:shortstring):shortstring;
Begin
  if length(st)=0 then result:=''
  else
   result:= rev(copy(st,2,length(st)-1))+ st[1];
End;

var s:shortstring;
begin
  write('stroka: ');
  readln(s);
  writeln(rev(s));
  readln;
end.


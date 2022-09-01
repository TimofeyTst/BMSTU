program SortirovkaMassiva1;

  const n=5;
  Type mas = array [1..n] of real; mas0 = array [0..n] of real;
  procedure vivod (T:mas);
  var i,len:integer;
  begin
     len:=length(t);
     for i:=1 to len do
     writeln ('T[',i,'] = ', T[i]:1:0);
  end;
  procedure vvod (var T:mas);
  var i,len:integer;
  begin
     len:=length(t);
     for i:=1 to len do
     readln (T[i]);
  end;
  procedure vvodRandom (var Ti:mas);
  var i,len,m:integer;
  begin
     write ('Diapazon randoma = ');
     readln(m);
     randomize;
     len:=length(ti);
     for i:=1 to len do
     Ti[i]:=random(m)+1;
  end;
  procedure sortI(var Ti:mas);
  var i,j,k,len:integer;
  begin
     len:=length(Ti);
    for i:=1 to len-1 do
  begin
      k:=i;
      for j:=i+1 to n do
          If Ti[j]<Ti[k] then
            k:=j;
      if k<>i then
        begin
          Ti[i]:=Ti[k]+Ti[i];
          Ti[k]:=Ti[i]-Ti[k];//в катом итый
          Ti[i]:=Ti[i]-Ti[k];
        end;
  end;
  end;
  procedure sortBuf(var Ti:mas0);
  var i,j:integer; b:real;
  begin
      for i:=2 to n do
      begin
      b:=Ti[i];
      Ti[0]:=b;
      j:=i-1;
      while b < Ti[j] do
      begin
        Ti[j+1]:=Ti[j];
        j:=j-1
      end;
      Ti[j+1]:=b;
      end;
  end;

var
    T:mas;
    T2:mas0;
    i:integer;
begin
  T[1]:=0;
  randomize;
            for i:=1 to n do
            begin
                 T2[i]:=random(10)+1;
            end;
  sortBuf(T2);
  writeln;
  writeln('Otsortirovanniy buf:');
  writeln;
    for i:=1 to n do
    writeln('T2[',i,'] = ',T2[i]:1:0);
  vvodRandom(t);
  sortI(t);
  writeln ('Otsortirovaniy I:');
  vivod(t);
readln
end.


program VstrechaStrelok;
Var H,M,ch,mun,t,w0:real;
  const w1=0.5; w2=6;
begin
  writeln('Write time: ');
  write('Hours: ');
  readln(H);
  If H>12 then
     writeln ('AM or PM')

  else
  write('Minutes: ');
  readln(M);
  w0:=w2-w1;
  ch:=w1*(H*60+M);
  mun:=w2*M;
            if ch>mun then
            t:=(ch-mun)/w0
            else t:=(360+ch-mun)/w0;
  writeln('Time first meeting= ',t:20:16, ' minutes');
  readln;
end.


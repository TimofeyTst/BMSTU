program Lab_6;
procedure pokaNeS(var s:string; i:integer);
var sn:char;
begin
  write('Symbol #',i,': ');
  readln (sn);
  s:=s+lowercase(sn);
  if sn=' ' then pokaNeS(s,i);
end;
 //Если вписали пробел, продолжаем читать до символа
var n,i,minP,minN,kslov,minIndex:integer; s,slovo:string; sn:char;

begin
  write('kol-vo symbols n = ');
  readln(n);
  s:=' ';
  for i:=1 to n do
  begin
  write('Symbol #',i,': ');
  readln (sn);
  s:=s+lowercase(sn);
  if sn=' ' then pokaNeS(s,i);
  end;                           //Прочитали n символов без пробелов
  s[length(s)+1]:=' '; //Чтобы посчитать слова добавили в конец пробел

  minP:=100000;
  kslov:=0;
  MinN:=0;
  slovo:=' ';
  for i:=1 to length(s) do
       if (ord(s[i])>96) and (ord(s[i])<123) then
       begin
            minN:=minN+1;//считаем длину и индексс минимального слова
            if  (s[i+1]=' ') then
               begin
                    kslov:=kslov+1;
                    if minN<minP then begin minP:=minN; minIndex:=i; end;
                    minN:=0;

               end;
       end;
  for i:=minIndex-minP+1 to minIndex do //В отдельную строку помещаю мин слово
  slovo:=slovo + s[i];
  //Далее вывод
  writeln('Stroka: ',s);
  writeln;
  writeln('Kol-vo slov = ', kslov);
  writeln(' Samoe maloe po dline slovo: "',slovo,' "','   Pri tom ego dlina = ',minP);

  readln

end.


program dz2_3;
var Mnoj:set of char;
    stroka:string;
    i,j,len:integer;
    count:char;
    key:boolean;
begin
  writeln('Vvedite stroky, v konce "."');
  readln(stroka);
  len:=length(stroka);
  stroka:=lowercase(stroka);
  Mnoj:=[];
  for i:=1 to len-1 do
      begin
      key:=true;
      for j:=i+1 to len do
          if key and (stroka[i]=stroka[j]) then
          begin
          key:=false;
          mnoj:=mnoj+[stroka[i]]
          end;
      end;
      writeln (stroka);
      for count:='a' to 'z' do
         if count in mnoj then write (count, ' ');
      readln
end.


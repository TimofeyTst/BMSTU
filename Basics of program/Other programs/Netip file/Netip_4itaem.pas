program Netip_4itaem;
const kzap=8;
      z=2;
type mas=array [1..10] of string[kzap*z-1];
var Netip:File;
    buf:mas;
    name:string;
    i,k:integer;
    key:boolean;
begin
  writeln('Input file name: ');
  readln(name);
  assign(netip,name);
  rewrite(netip,z);
  i:=1;
  key:=true;
  while key do
  begin
       writeln('Input block of 15 symbols: ');
       readln(buf[i]);
       for k:=1 to kzap*z-1 do
           if buf[i][k]='#' then
              key:=false;
       blockwrite(netip,buf[i],kzap);
       i:=i+1;
  end;

  closefile(netip);
  readln;
end.


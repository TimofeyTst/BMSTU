program Netipok;
const kzap=1;
      z=16;
type mas=array [1..kzap*z] of char;
var Netip:File;
    buf:mas;
    Tipok:file of mas;
    name:string;
    i,k:integer;
begin
  writeln('Input file name: ');
  readln(name);
  assign(netip,name);
  reset(netip,z);
  assign(tipok,'Soxranil.txt');
  rewrite(tipok);
  while not eof(netip) do
  begin
  blockread(netip,buf,kzap,i);
  if i=kzap then
  write(tipok,buf);
  for k:=1 to i do
  write(buf[k]);
  end;
  closefile(tipok);
  closefile(netip);
  readln;
end.


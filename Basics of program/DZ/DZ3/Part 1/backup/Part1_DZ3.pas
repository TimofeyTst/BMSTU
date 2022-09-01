program Part1_DZ3;

Type Nakopitel=object
  private brend:string;
  private size:integer;
  procedure Init(ib:string; isz:integer);
  procedure Print;
  function RSize:extended;
  end;

  procedure Nakopitel.Init(ib:string; isz:integer);
  begin
       Brend:=ib;
       size:=isz;
  end;
  procedure Nakopitel.Print;
  begin
       writeln('Brend nakopitelya: ',brend);
       writeln('Size of: ',size,' Gb');
       writeln('Real size of: ',Rsize:4:2,' Gb');
  end;
  function Nakopitel.Rsize:extended;
  begin
       result:=(size*(1000000000/1024/1024/1024));
  end;

  var Flesh:Nakopitel;
begin
     Flesh.Init('intel',8);
     Flesh.print;
     writeln(Flesh.size);
     readln;
end.


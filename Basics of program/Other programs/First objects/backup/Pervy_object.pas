program Pervy_object;
uses sysUtils;
Type Troom=object
      line,weight:single;
      function square:single;
      procedure Init(il,iw:single);
  end;
procedure Troom.init(il,iw:single);
begin
     line:=il;
     weight:=iw;
end;
function Troom.square:single;
begin
     result:=line*weight;
end;
//Next object:
Type ITroom=object(troom)
     height:single;
     function volume:single;
     procedure newInit(ih,il,iw:single);
     end;
function ITroom.volume:single;
begin
     result:=height*ITroom.square;
end;
procedure ITroom.NewInit(ih,il,iw:single);
begin
     ITroom.init(il,iw);
     height:=ih;
end;




var kitchen:troom;
    IKitchen:ITroom;
begin
     writeln('Posmotrim, kakoy kod you have written: ');
     kitchen.init(5,7);
     Ikitchen.newinit(5,7,3);
     writeln('Square = ',kitchen.square:5:1);
     writeln('Square = ',Ikitchen.volume:5:1);
     writeln('Free on disk: ',disksize(3)/1024/1024/1024:20:10);
     readln;

end.


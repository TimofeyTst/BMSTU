program DZ3_Part2;
Type Auto=object
     private Brend:string;
     private SrSpeed:integer;
     procedure Init(ib:string;isr:integer);
     procedure Print(s:single);
     function Time(s:single):single;
     end;
Type ArendaAuto=object(Auto)
     private company,model:string;
     private PricePerMinute:integer;
     function price(s:single):single;
     procedure Initil(ic,ib,im:string;isr,ippm:integer);
     procedure Print(s:single);
     end;

  procedure Auto.Init(ib:string;isr:integer);
  begin
       Brend:=ib;
       Srspeed:=isr;
  end;
  procedure Auto.Print(s:single);
  begin
       Writeln('Automobile marks: ',brend);
       writeln('Its average speed: ',srspeed,' km/h');
       writeln('Dannoe rasstoyaniye proedet za: ',time(s):2:1,' hours');
  end;
  function Auto.time(s:single):single;
  begin
       result:=s/srspeed;
  end;

  procedure ArendaAuto.initil(ic,ib,im:string;isr,ippm:integer);
     begin
          Init(ib,isr);
          company:=ic;
          model:=im;
          PricePerMinute:=ippm;
     end;
  procedure ArendaAuto.Print(s:single);
     begin
          Writeln('Automobile marks and models: ',brend,' ',model);
          Writeln('Belong`s ',company,' organisation');
          writeln('Its average speed: ',srspeed,' km/h');
          writeln('Dannoe rasstoyaniye proedet za: ',time(s):2:1,' hours');
          writeln('Price: ',price(s):6:1,'$');
     end;
  function ArendaAuto.price(s:single):single;
     begin
          result:=time(s)*60*PricePerMinute;
     end;
var
    Polo:Auto;
    Camaro:ArendaAuto;
    dist:single;
    key:char;
begin
     Polo.init('Volkswagen',90);
     camaro.initil('Yandex','Shevrolet','Camaro ZL1',140,1);
     writeln;
     key:='o';
     while key<>#13 do begin
     write('Input any distance: ');
     readln(dist);
     writeln;
     Polo.print(dist);
     writeln;
     writeln('Arendovany:');
     Camaro.print(dist);
     writeln;
     writeln('Enter to end, write smth to continue');
     readln(key);
     end;
end.


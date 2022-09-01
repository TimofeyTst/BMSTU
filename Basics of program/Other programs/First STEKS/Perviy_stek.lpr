program Perviy_stek;
//LiFo
Type ykaz=^el;
  el=record
    n:string;
    next:ykaz;
    end;
  procedure sozd_stek(var first:ykaz);
  var
    q:ykaz;
    s:string;
  begin
        q:=nil;
        Write('Input number or "end": ');
        readln(s);
        if s<>'end' then
        begin
          new(first);
          first^.n:=s;
          first^.next:=nil;
          Write('Input number or "end": ');
          readln(s);
          while s<>'end' do
                begin
                      new(q);
                      q^.n:=s;
                      q^.next:=first;
                      first:=q;
                      Write('Input number or "end": ');
                      readln(s);
                end;
          end;
  end;
  procedure view_stek(var first:ykaz; var key:boolean);
  var q:ykaz;
  begin
        if first<>nil then
         begin
         q:=first;
         while q<>nil do
           begin
                write(q^.n);
                q:=q^.next;
           end;
         writeln;
         end
         else begin
                   writeln('Error: list is empty');
                   writeln('Write smth in your list fucking idiot!');
                   key:=false;
                   readln;
                   halt;
               end;
  end;
  procedure sozd_ochered(var first:ykaz);
  var s:string;
      q:ykaz;
     begin
           write ('Input num or "end": ');
           readln(s);
           if s<>'end' then
             begin
                  new(first);
                  first^.n:=s;
                  first^.next:=nil;
                  write('Input num or "end": ');
                  readln(s);
                  q:=first;
                  while s<>'end' do
                  begin
                       new(q^.next);
                       q:=q^.next;
                       q^.n:=s;
                       q^.next:=nil;
                       write('Input num or "end": ');
                       readln(s);
                  end;
                  writeln;
             end;

     end;
  procedure view_ochered(var first:ykaz; var key:boolean);
  var q:ykaz;
      begin
           q:=first;
           if q<>nil then
           while q<>nil do
             begin
                   write(q^.n);
                   q:=q^.next;
             end
           else begin
                   writeln('Error: list is empty');
                   writeln('Write smth in your list fucking idiot!');
                   key:=false;
                   readln;
                   halt;
               end;
           writeln;
      end;
  procedure Vstavka_stek(var first:ykaz);
  var q,posle:ykaz;
      s:string;
      i,k:integer;
  begin
       new(q);
       i:=1;
       writeln('Input num: ');
       readln(s);
       writeln('Input position vstavki: ');
       readln(k);
       posle:=first;
       while i<k do
         begin
              i:=i+1;
              posle:=posle^.next;
         end;
       q^.n:=s;
       q^.next:=posle^.next;
       posle^.next:=q;
  end;

var first:ykaz;
  key:boolean;
begin
     key:=true;
     first:=nil;

     sozd_ochered(first);
     writeln('Enter to see your list');
     readln;
     view_ochered(first,key);

     if key then writeln('Enter to end programm');
     readln;
end.

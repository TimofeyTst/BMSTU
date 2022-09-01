unit my_math;

{$mode objfpc}{$H+}

interface
uses
   Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, math;

Type line_without = object
     point_n,point_k:Tpoint;
     procedure begin_init (ipoint_n:Tpoint);
     procedure end_init(ipoint_k:Tpoint);
     end;

     line_with_round = object (line_without)
          point_n_round,point_k_round:Tpoint;
          cosa,sina,tga:double;
          procedure end_init (a:integer;ipoint_k:Tpoint);
     end;
     function situation (xn,xk,yn,yk:integer):integer;

implementation
procedure line_without.begin_init (ipoint_n:Tpoint);
  begin
       point_n.x:=ipoint_n.x;
       point_n.y:=ipoint_n.y;
  end;
procedure line_without.end_init (ipoint_k:Tpoint);
  begin
       point_k.x:=ipoint_k.x;
       point_k.y:=ipoint_k.y;
  end;

procedure line_with_round.end_init (a:integer;ipoint_k:Tpoint);
    var s : integer;
  begin
       inherited end_init(ipoint_k);
       if  (point_k.x-point_n.x) = 0 then tga := 0
       else begin
       tga:= abs((point_k.Y-point_n.y)/(point_k.x-point_n.x));
       cosa:= sqrt(1/(1+sqr(tga)));
       sina:= sqrt(1-sqr(cosa));
       end;
       s := round ( a/3);
        case situation (point_n.x,point_k.x,point_n.y,point_k.y) of
        1:   begin point_n_round.x := round(point_k.x + a * sqrt(2) * cosa - s - a);
             point_n_round.y := round (point_k.y - a * sqrt(2) * sina + s + a);
             point_k_round.x := round (point_k.x + a * sqrt(2) * cosa + a);
             point_k_round.y := round (point_k.y - a * sqrt(2) * sina - a);
             end;
        2:   begin point_n_round.x := round (point_k.x - a * sqrt(2) * cosa + s + a);
             point_n_round.y := round (point_k.y - a * sqrt(2) * sina + s + a );
             point_k_round.x := round (point_k.x - a * sqrt(2) * cosa - a);
             point_k_round.y := round (point_k.y - a * sqrt(2) * sina + s - a);
             end;
        3:   begin point_n_round.x := round (point_k.x - a * sqrt(2) * cosa + s + a);
             point_n_round.y := round (point_k.y + a * sqrt(2) * sina - s - a );
             point_k_round.x := round (point_k.x - a * sqrt(2) * cosa -a);
             point_k_round.y := round (point_k.y + a * sqrt(2) * sina + a );
             end;
        4:   begin point_n_round.x := round (point_k.x + a * sqrt(2) * cosa - s - a);
             point_n_round.y := round (point_k.y + a * sqrt(2) * sina - s - a);
             point_k_round.x := round (point_k.x + a * sqrt(2) * cosa + a);
             point_k_round.y := round (point_k.y + a * sqrt(2) * sina + a);
             end;
        5:   begin point_n_round.x := point_k.x - a;
             point_n_round.y := point_k.y + a;
             point_k_round.x := point_k.x + a;
             point_k_round.y := point_k.y - a;
             end;
        6:   begin point_n_round.x := point_k.x + a;
             point_n_round.y := point_k.y;
             point_k_round.x := point_k.x - a;
             point_k_round.y := point_k.y + 2 * a;
             end;
        7:   begin point_n_round.x := point_k.x + a;
             point_n_round.y := point_k.y;
             point_k_round.x := point_k.x - a;
             point_k_round.y := point_k.y - 2 * a;
             end;
        8:   begin point_n_round.x := point_k.x - 2 * a;
             point_n_round.y := point_k.y + a;
             point_k_round.x := point_k.x + a;
             point_k_round.y := point_k.y - a;
             end;
        9:   begin point_n_round.x := point_k.x;
             point_n_round.y := point_k.y + a;
             point_k_round.x := point_k.x + 2 * a;
             point_k_round.y := point_k.y - a;
             end;
  end;
  end;

 function situation (xn,xk,yn,yk:integer):integer;
 begin
      if (xk-xn>0) and (yk-yn<0) then result := 1
      else if (xk-xn<0) and (yk-yn<0) then result := 2
      else if (xk-xn<0) and (yk-yn>0) then result := 3
      else if (xk-xn>0) and (yk-yn>0) then result := 4
      else if (xk-xn=0) and (yk-yn=0) then result := 5
      else if (xk-xn=0) and (yk-yn>0) then result := 6
      else if (xk-xn=0) and (yk-yn<0) then result := 7
      else if (xk-xn<0) and (yk-yn=0) then result := 8
      else if (xk-xn>0) and (yk-yn=0) then result := 9;
 end;

end.


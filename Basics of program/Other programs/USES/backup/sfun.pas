Unit SFun;
 Interface
   Type func=function(x:Single):Single;
   Procedure TabFun(f:func;a,b:Single;n:integer;
                   var Masf,MasX:array of Single);
 Implementation
 Procedure TabFun(f:func;a,b:Single;n:integer;
                   var Masf,MasX:array of Single);;
  Var h,x:Single;   i:integer;
  Begin
     h:=(b-a)/(n-1);
     for i:=0 to n-1 do
       begin MasX[i]:= a+h*i;
             Masf[i]:=f(MasX[i]);
       end;
  End;
End.

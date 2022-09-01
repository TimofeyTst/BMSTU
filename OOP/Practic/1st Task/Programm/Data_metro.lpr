program Data_metro;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, Main_Form, Pass_form, Form_dedit, Data_base_form, graphic_form
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TMain, Main);
  Application.CreateForm(TPassword, Password);
  Application.CreateForm(TAccess, Access);
  Application.CreateForm(TData_base, Data_base);
  Application.CreateForm(TGraphic_trams, Graphic_trams);
  Application.Run;
end.


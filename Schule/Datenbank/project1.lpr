program project1;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms
  { add your units here }, Unit1, Unit2;

begin
  Application.Title:='Buchung';
  Application.Initialize;
  Application.CreateForm(TBuchung, Buchung);
  Application.CreateForm(THinweis, Hinweis);
  Application.Run;
end.


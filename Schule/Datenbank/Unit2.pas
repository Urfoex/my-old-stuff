unit Unit2; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, LResources, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Buttons;

type

  { THinweis }

  THinweis = class(TForm)
    Achtung: TLabel;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);

  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Hinweis: THinweis;

implementation

{ THinweis }







procedure THinweis.Button1Click(Sender: TObject);
begin
  close
end;

initialization
  {$I Unit2.lrs}

end.


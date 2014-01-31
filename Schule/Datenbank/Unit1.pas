unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, LResources, Forms, Controls, Graphics, Dialogs, ExtCtrls,
  StdCtrls, Buttons, Unit2;

type

  { TBuchung }

  TBuchung = class(TForm)
    Beenden: TButton;
    Beguenstigter: TGroupBox;
    Betrag: TEdit;
    Geldbetrag: TGroupBox;
    Kontoinhaber: TGroupBox;
    Kontonummer_: TLabeledEdit;
    Credits: TLabel;
    Laden_: TButton;
    Name_: TLabeledEdit;
    Passwort: TLabeledEdit;
    Ueberweisen: TButton;
    Vorname_: TLabeledEdit;
    _Kontonummer: TLabeledEdit;
    _Laden: TButton;
    _Name: TLabeledEdit;
    _Vorname: TLabeledEdit;
    procedure _LadenClick(Sender: TObject);
    procedure BeendenClick(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Buchung: TBuchung;
  filein, fileout : text;
  aoc:array[0..7] of char;
implementation

{ TBuchung }

procedure TBuchung.BeendenClick(Sender: TObject);
begin
  close;
end;

procedure TBuchung._LadenClick(Sender: TObject);
begin
  if(Name_.Text='') then  Hinweis.ShowModal
  else
  begin
       if(Vorname_.Text='') then  Hinweis.ShowModal
       else
       begin
           if(Passwort.Text='') then  Hinweis.ShowModal
           else
           begin
               if(Kontonummer_.Text='') then  Hinweis.ShowModal
               else
               begin
                     assign(filein,'C:\169472746.txt');
                     reset(filein);
                     readln(filein, aoc);
                     if(aoc=Passwort.Text) then
                     begin
                          _Name.enabled:=TRUE;
                          _Vorname.enabled:=TRUE;
                          _Kontonummer.enabled:=TRUE;
                          Laden_.enabled:=TRUE;
                     end;
               end
           end;
       end;
  end;
end;

initialization
  {$I Unit1.lrs}

end.


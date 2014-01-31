(*Darstellung einer quadratischen Funktion*)
(*erarbeitet von Manuel Bellersen , 20.04.2005*)
(*Kakarott2003@yahoo,ICQ: 169472746*)
(*Homepage: www.Xom-I-moX.de.vu*)
(*#############################################*)

PROGRAM qugraph;
USES Crt, Graph;
VAR Treiber, Modus: smallint;
var i,x1,x2,y,x11,x22,y1:integer;

BEGIN





DetectGraph (Treiber, Modus);
InitGraph (Treiber, Modus, 'C:\Turbo\BGI');


(*Koordinatensystem*)
SetColor (red);
line(275,0,275,576);
line(0,576,576,576);
OutTextXY(574,573,'> X');
outtextxy(272,0,'^Y');
line(287,571,287,581);
outtextxy(285,586,'1');
line(270,564,280,564);
outtextxy(281,560,'1');

(*Parabell zeichnen*)
SetColor (green);
outtextxy(20,10,'f(x)=x^2');
outtextxy(20,25,'Intervall -x: -24');
outtextxy(20,40,'Intervall +x: 24');

for i:=1 to 24 do
begin
     x1:=i+22;
     x11:=i+23;
     y:=i*i;
     y1:=(i+1)*(i+1);
     x2:=-i+23;
     x22:=-i+24;
    line(12*x1,576-y,12*x11,576-y1);
    line(12*x2,576-y1,12*x22,576-y);
end;

repeat until readkey <> '';

CloseGraph;
END.

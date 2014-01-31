(*Darstellung einer Sinusfunktion*)
(*erarbeitet von Manuel Bellersen , 20.04.2005*)
(*Kakarott2003@yahoo,ICQ: 169472746*)
(*Homepage: www.Xom-I-moX.de.vu*)
(*#############################################*)

PROGRAM singraph;
USES Crt, Graph;
VAR Treiber, Modus: smallint;
var i,x1,x2,y,x11,x22,y1:integer;

BEGIN
DetectGraph (Treiber, Modus);
InitGraph (Treiber, Modus, 'C:\Turbo\BGI');


(*Koordinatensystem*)
SetColor (red);
line(307,0,307,576);
line(0,276,767,276);
OutTextXY(764,273,'> X');
outtextxy(304,0,'^Y');
line(613,270,613,280);
outtextxy(611,285,'2PI');
line(302,173,312,173);
outtextxy(313,170,'1');

(*Sinus zeichnen*)
SetColor (green);
outtextxy(20,10,'f(x)=sin(x)');
outtextxy(20,25,'Intervall -x: -2PI');
outtextxy(20,40,'Intervall +x: 3PI');

for i:=1 to 767 do
begin
     y:=trunc(trunc(sin((i-1)/48.75)*100));
     putpixel(i,276-y,green);
end;

delay(30000);
CloseGraph;
END.


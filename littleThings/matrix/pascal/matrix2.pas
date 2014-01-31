////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dies ist ein Matrix-artiges Program, welches von Manuel Bellersen, alias Kakarott, in Pascal verfasst wurde. Von mir aus könnt ihr den Code frei verändern //
// und erweitern. Für Kritik und andere Dinge könnt ihr euch per eM@il: Kakarott2003@yahoo.de oder ICQ: 169472746 an mich wenden. Viel Spaß beim benutzen.    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

program matrix;
uses crt;

label jump;

var z,d,e,f,a,b,c:integer;
var ya,yb,yc,ye,yf,yg,yh,yi,yk:integer;
var xa,xb,xc,xe,xf,xg,xh,xi,xk:integer;
var zeichen:char;

begin
jump:

a:=24;
b:=25;
c:=79;

ya:=b;
yb:=b;
yc:=b;
ye:=b;
yf:=b;
yg:=b;
yh:=b;
yi:=b;
yk:=b;

clrscr;
textcolor(2);
gotoxy(1,1);
write('Wie viel Durchläufe?: ');
readln(d);
write('Geschwindigkeit?: ');
readln(f);
clrscr;


for z:=d downto 0 do
begin

    if(ya=b) then
    begin
        ya:=trunc(random(a));
        xa:=trunc(random(c));
        if(xa=1) then
            xa:=2;
    end;
    textcolor(green);
    zeichen:=char(trunc(random(255)));
    gotoxy(xa,ya);
    write(zeichen);
    ya:=ya+1;

    if(yb=b) then
    begin
        yb:=trunc(random(a));
        xb:=trunc(random(c));
        if(xb=1) then
            xb:=2;
    end;
    textcolor(green);
    zeichen:=char(trunc(random(255)));
    gotoxy(xb,yb);
    write(zeichen);
    yb:=yb+1;

    if(yc=b) then
    begin
        yc:=trunc(random(a));
        xc:=trunc(random(c));
        if(xc=1) then
            xc:=2;
    end;
    textcolor(green);
    zeichen:=char(trunc(random(255)));
    gotoxy(xc,yc);
    write(zeichen);
    yc:=yc+1;



    if(ye=b) then
    begin
        ye:=1;
        xe:=trunc(random(c));
        if(xe=1) then
            xe:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xe,ye);
    write(zeichen);
    ye:=ye+1;

    if(yf=b) then
    begin
        yf:=1;
        xf:=trunc(random(c));
        if(xf=1) then
            xf:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xf,yf);
    write(zeichen);
    yf:=yf+1;

    if(yg=b) then
    begin
        yg:=1;
        xg:=trunc(random(c));
        if(xg=1) then
            xg:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xg,yg);
    write(zeichen);
    yg:=yg+1;



    if(yh=b) then
    begin
        yh:=1;
        xh:=trunc(random(c));
        if(xh=1) then
            xh:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xh,yh);
    write(zeichen);
    yh:=yh+1;

    if(yi=b) then
    begin
        yi:=1;
        xi:=trunc(random(c));
        if(xi=1) then
            xi:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xi,yi);
    write(zeichen);
    yi:=yi+1;

    if(yk=b) then
    begin
        yk:=1;
        xk:=trunc(random(c));
        if(xk=1) then
            xk:=2;
    end;
    textcolor(0);
    zeichen:=char(trunc(random(255)));
    gotoxy(xk,yk);
    write(zeichen);
    yk:=yk+1;


    z:=z-1;
delay(f);
end;

clrscr;
textcolor(2);
gotoxy(1,1);
write('Noch mal(1=ja,0=nein)?: ');
readln(e);
if(e>0) then
    goto jump;


end.

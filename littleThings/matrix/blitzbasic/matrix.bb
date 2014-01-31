;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;// Diese ist ein sehr einfacher Matrix-Bildschirmschoner, welcher von Manuel Bellersen, alias Kakarott, in BB im November 2004 programmiert wurde. Viel Spaß in der Matrix. Fragen etc an Kakarott2003@yahoo.de ///////////////////////////////////
;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AppTitle "Matrix"
Graphics 640,480,16,1

.jump


schwarz=CreateImage(10,16)
SetBuffer ImageBuffer(schwarz)
For a=1 To 10
	For b=1 To 16
		WritePixel a,b,0
	Next
Next

SetBuffer FrontBuffer()

a=FileType("C:\matrix")
If (a=0) Then
	Color 0,255,0
	ClsColor 0,0,0
	Cls
	f=Input("Geschwindigkeit?: ")
	Cls
	offen=WriteFile("C:\matrix")
	WriteInt offen,f
	CloseFile offen
Else
	offen=ReadFile("C:\matrix")
	f=ReadInt(offen)
	CloseFile offen;
EndIf
	
flushkeys







a=479
b=480
c=639
i= 10
k=15
l=111111





ya=b
yb=b
yc=b
ye=b
yf=b
yg=b
yh=b
yi=b
yk=b

Repeat


If(ya>b) Then
	ya=Rand(a)
	xa=Rand(c)
	xa=(Ceil#(xa/10)*10)
EndIf

Color 0,255,0
zeichen$=Chr(Rand(255))
DrawBlock schwarz,xa,ya
Text xa,ya,zeichen$
ya=ya+15

If(yb>b) Then
	yb=Rand(a)
	xb=Rand(c)
	xb=(Ceil#(xb/10)*10)
EndIf

Color 0,255,0
zeichen$=Chr(Rand(255))
DrawBlock schwarz,xb,yb
Text xb,yb,zeichen$
yb=yb+15

If(yc>b) Then
	yc=Rand(a)
	xc=Rand(c)
	xc=(Ceil#(xc/10)*10)
EndIf

Color 0,255,0
zeichen$=Chr(Rand(255))
DrawBlock schwarz,xc,yc
Text xc,yc,zeichen$
yc=yc+15






If(yg>b) Then
	yg=Rand(a)
	xg=Rand(c)
	xg=(Ceil#(xg/10)*10)
EndIf


DrawBlock schwarz,xg,yg
yg=yg+15

If(ye>b) Then
	ye=Rand(a)
	xe=Rand(c)
	xe=(Ceil#(xe/10)*10)
EndIf


DrawBlock schwarz,xe,ye
ye=ye+15

If(yf>b) Then
	yf=Rand(a)
	xf=Rand(c)
	xf=(Ceil#(xf/10)*10)
EndIf


DrawBlock schwarz,xf,yf
yf=yf+15


If(yh>b) Then
	yh=Rand(a)
	xh=Rand(c)
	xh=(Ceil#(xh/10)*10)
EndIf


DrawBlock schwarz,xh,yh
yh=yh+15

If(yi>b) Then
	yi=Rand(a)
	xi=Rand(c)
	xi=(Ceil#(xi/10)*10)
EndIf


DrawBlock schwarz,xi,yi
yi=yi+15

If(yk>b) Then
	yk=Rand(a)
	xk=Rand(c)
	xk=(Ceil#(xk/10)*10)
EndIf


DrawBlock schwarz,xk,yk
yk=yk+15


If KeyHit(1) Then
	FreeImage schwarz
	End
EndIf

Delay f


Forever

End
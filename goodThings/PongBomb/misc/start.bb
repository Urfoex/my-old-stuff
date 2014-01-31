;so 

.begin


;auf zum Spiel

rechts=280
xco=260
yco=430
m=4
n=4

;Hier gehts los

Dim grau.stein(10,8)


For a=1 To 10
 For b=1 To 8
    grau.stein(a,b)=New stein
    grau(a,b)\energie=1
  grau(a,b)\art=2 
 
 Next
Next








SetBuffer BackBuffer()

While Not KeyHit(1)


;Steuerung festlegen

If KeyDown(205) rechts=rechts+8
If KeyDown(203) rechts=rechts-8


;Rand festlegen

If rechts<40 rechts=40
If rechts>600 rechts=600


;Bilder + Steuerung löschen

FlushKeys
Cls




;Bilder zeigen
;Brett

DrawImage brett,rechts,460

Color 0,255,0


;Steine

;Die Art
a=1
b=2
c=3
d=4
g=5
h=6
i=7
j=8
k=9
l=10


;1

  If  ImagesOverlap(ball,xco,yco,block,10,5) Then
    grau(a,a)\energie=0
    grau(a,a)\art=0
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,73,5) Then
  grau(b,a)\energie=0 
  grau(b,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,136,5) Then 
  grau(c,a)\energie=0 
  grau(c,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,199,5) Then
  grau(d,a)\energie=0 
  grau(d,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,262,5) Then 
  grau(g,a)\energie=0 
  grau(g,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,325,5) Then 
  grau(h,a)\energie=0
  grau(h,a)\art=0
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,388,5) Then
  grau(i,a)\energie=0 
  grau(i,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,451,5) Then 
   grau(j,a)\energie=0 
   grau(j,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,514,5) Then 
   grau(k,a)\energie=0 
   grau(k,a)\art=0 
  EndIf
  If  ImagesOverlap(ball,xco,yco,block,577,5) Then 
  grau(l,a)\energie=0 
  grau(l,a)\art=0 
  EndIf

;2

  If  ImagesOverlap(ball,xco,yco,block,10,35) grau(a,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,35) grau(b,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,35) grau(c,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,35) grau(d,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,35) grau(g,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,35) grau(h,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,35) grau(i,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,35) grau(j,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,35) grau(k,b)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,35) grau(l,b)\energie=0 And m=-m And n=-n

;3

  If  ImagesOverlap(ball,xco,yco,block,10,65) grau(a,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,65) grau(b,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,65) grau(c,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,65) grau(d,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,65) grau(g,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,65) grau(h,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,65) grau(i,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,65) grau(j,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,65) grau(k,c)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,65) grau(l,c)\energie=0 And m=-m And n=-n

;4

  If  ImagesOverlap(ball,xco,yco,block,10,95) grau(a,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,95) grau(b,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,95) grau(c,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,95) grau(d,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,95) grau(g,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,95) grau(h,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,95) grau(i,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,95) grau(j,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,95) grau(k,d)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,95) grau(l,d)\energie=0 And m=-m And n=-n

;5

  If  ImagesOverlap(ball,xco,yco,block,10,125) grau(a,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,125) grau(b,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,125) grau(c,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,125) grau(d,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,125) grau(g,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,125) grau(h,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,125) grau(i,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,125) grau(j,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,125) grau(k,g)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,125) grau(l,g)\energie=0 And m=-m And n=-n

;6

  If  ImagesOverlap(ball,xco,yco,block,10,155) grau(a,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,155) grau(b,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,155) grau(c,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,155) grau(d,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,155) grau(g,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,155) grau(h,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,155) grau(i,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,155) grau(j,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,155) grau(k,h)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,155) grau(l,h)\energie=0 And m=-m And n=-n

;7

  If  ImagesOverlap(ball,xco,yco,block,10,185) grau(a,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,185) grau(b,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,185) grau(c,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,185) grau(d,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,185) grau(g,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,185) grau(h,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,185) grau(i,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,185) grau(j,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,185) grau(k,i)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,185) grau(l,i)\energie=0 And m=-m And n=-n

;8

  If  ImagesOverlap(ball,xco,yco,block,10,215) grau(a,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,73,215) grau(b,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,136,215) grau(c,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,199,215) grau(d,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,262,215) grau(g,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,325,215) grau(h,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,388,215) grau(i,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,451,215) grau(j,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,514,215) grau(k,j)\energie=0 And m=-m And n=-n
  If  ImagesOverlap(ball,xco,yco,block,577,215) grau(l,j)\energie=0 And m=-m And n=-n













;Reihe 1
f=1

If Not grau(1,f)\energie=0 DrawImage block,10,5,0
If Not grau(2,f)\energie=0 DrawImage block,73,5,0
If Not grau(3,f)\energie=0 DrawImage block,136,5,0
If Not grau(4,f)\energie=0 DrawImage block,199,5,0
If Not grau(5,f)\energie=0 DrawImage block,262,5,0
If Not grau(6,f)\energie=0 DrawImage block,325,5,0
If Not grau(7,f)\energie=0 DrawImage block,388,5,0
If Not grau(8,f)\energie=0 DrawImage block,451,5,0
If Not grau(9,f)\energie=0 DrawImage block,514,5,0
If Not grau(10,f)\energie=0 DrawImage block,577,5,0


;2
f=2
If Not grau(1,f)\energie=0 DrawImage block,10,35,0
If Not grau(2,f)\energie=0 DrawImage block,73,35,0
If Not grau(3,f)\energie=0 DrawImage block,136,35,0
If Not grau(4,f)\energie=0 DrawImage block,199,35,0
If Not grau(5,f)\energie=0 DrawImage block,262,35,0
If Not grau(6,f)\energie=0 DrawImage block,325,35,0
If Not grau(7,f)\energie=0 DrawImage block,388,35,0
If Not grau(8,f)\energie=0 DrawImage block,451,35,0
If Not grau(9,f)\energie=0 DrawImage block,514,35,0
If Not grau(10,f)\energie=0 DrawImage block,577,35,0

;3
f=3
If Not grau(1,f)\energie=0 DrawImage block,10,65,1
If Not grau(2,f)\energie=0 DrawImage block,73,65,1
If Not grau(3,f)\energie=0 DrawImage block,136,65,1
If Not grau(4,f)\energie=0 DrawImage block,199,65,1
If Not grau(5,f)\energie=0 DrawImage block,262,65,1
If Not grau(6,f)\energie=0 DrawImage block,325,65,1
If Not grau(7,f)\energie=0 DrawImage block,388,65,1
If Not grau(8,f)\energie=0 DrawImage block,451,65,1
If Not grau(9,f)\energie=0 DrawImage block,514,65,1
If Not grau(10,f)\energie=0 DrawImage block,577,65,1

;4
f=4
If Not grau(1,f)\energie=0 DrawImage block,10,95,1
If Not grau(2,f)\energie=0 DrawImage block,73,95,1
If Not grau(3,f)\energie=0 DrawImage block,136,95,1
If Not grau(4,f)\energie=0 DrawImage block,199,95,1
If Not grau(5,f)\energie=0 DrawImage block,262,95,1
If Not grau(6,f)\energie=0 DrawImage block,325,95,1
If Not grau(7,f)\energie=0 DrawImage block,388,95,1
If Not grau(8,f)\energie=0 DrawImage block,451,95,1
If Not grau(9,f)\energie=0 DrawImage block,514,95,1
If Not grau(10,f)\energie=0 DrawImage block,577,95,1

;5
f=5
If Not grau(1,f)\energie=0 DrawImage block,10,125,2
If Not grau(2,f)\energie=0 DrawImage block,73,125,2
If Not grau(3,f)\energie=0 DrawImage block,136,125,2
If Not grau(4,f)\energie=0 DrawImage block,199,125,2
If Not grau(5,f)\energie=0 DrawImage block,262,125,2
If Not grau(6,f)\energie=0 DrawImage block,325,125,2
If Not grau(7,f)\energie=0 DrawImage block,388,125,2
If Not grau(8,f)\energie=0 DrawImage block,451,125,2
If Not grau(9,f)\energie=0 DrawImage block,514,125,2
If Not grau(10,f)\energie=0 DrawImage block,577,125,2

;6
f=6
If Not grau(1,f)\energie=0 DrawImage block,10,155,2
If Not grau(2,f)\energie=0 DrawImage block,73,155,2
If Not grau(3,f)\energie=0 DrawImage block,136,155,2
If Not grau(4,f)\energie=0 DrawImage block,199,155,2
If Not grau(5,f)\energie=0 DrawImage block,262,155,2
If Not grau(6,f)\energie=0 DrawImage block,325,155,2
If Not grau(7,f)\energie=0 DrawImage block,388,155,2
If Not grau(8,f)\energie=0 DrawImage block,451,155,2
If Not grau(9,f)\energie=0 DrawImage block,514,155,2
If Not grau(10,f)\energie=0 DrawImage block,577,155,2

;7
f=7
If Not grau(1,f)\energie=0 DrawImage block,10,185,3
If Not grau(2,f)\energie=0 DrawImage block,73,185,3
If Not grau(3,f)\energie=0 DrawImage block,136,185,3
If Not grau(4,f)\energie=0 DrawImage block,199,185,3
If Not grau(5,f)\energie=0 DrawImage block,262,185,3
If Not grau(6,f)\energie=0 DrawImage block,325,185,3
If Not grau(7,f)\energie=0 DrawImage block,388,185,3
If Not grau(8,f)\energie=0 DrawImage block,451,185,3
If Not grau(9,f)\energie=0 DrawImage block,514,185,3
If Not grau(10,f)\energie=0 DrawImage block,577,185,3

;8
f=8
If Not grau(1,f)\energie=0 DrawImage block,10,215,3
If Not grau(2,f)\energie=0 DrawImage block,73,215,3
If Not grau(3,f)\energie=0 DrawImage block,136,215,3
If Not grau(4,f)\energie=0 DrawImage block,199,215,3
If Not grau(5,f)\energie=0 DrawImage block,262,215,3
If Not grau(6,f)\energie=0 DrawImage block,325,215,3
If Not grau(7,f)\energie=0 DrawImage block,388,215,3
If Not grau(8,f)\energie=0 DrawImage block,451,215,3
If Not grau(9,f)\energie=0 DrawImage block,514,215,3
If Not grau(10,f)\energie=0 DrawImage block,577,215,3








;Und wenn alle steine weg???

If grau(1,1)\energie=0 And grau(2,1)\energie=0  And grau(3,1)\energie=0 And grau(4,1)\energie=0 And grau(5,1)\energie=0 And grau(6,1)\energie=0 And grau(7,1)\energie=0 And grau(8,1)\energie=0 And grau(9,1)\energie=0 And grau(10,1)\energie=0 And grau(1,2)\energie=0 And grau(2,2)\energie=0  And grau(3,2)\energie=0 And grau(4,2)\energie=0 And grau(5,2)\energie=0 And grau(6,2)\energie=0 And grau(7,2)\energie=0 And grau(8,2)\energie=0 And grau(9,2)\energie=0 And grau(10,2)\energie=0 And grau(1,3)\energie=0 And grau(2,3)\energie=0  And grau(3,3)\energie=0 And grau(4,3)\energie=0 And grau(5,3)\energie=0 And grau(6,3)\energie=0 And grau(7,3)\energie=0 And grau(8,3)\energie=0 And grau(9,3)\energie=0 And grau(10,3)\energie=0 And grau(1,4)\energie=0 And grau(2,4)\energie=0  And grau(3,4)\energie=0 And grau(4,4)\energie=0 And grau(5,4)\energie=0 And grau(6,4)\energie=0 And grau(7,4)\energie=0 And grau(8,4)\energie=0 And grau(9,4)\energie=0 And grau(10,4)\energie=0 And grau(1,5)\energie=0 And grau(2,5)\energie=0  And grau(3,5)\energie=0 And grau(4,5)\energie=0 And grau(5,5)\energie=0 And grau(6,5)\energie=0 And grau(7,5)\energie=0 And grau(8,5)\energie=0 And grau(9,5)\energie=0 And grau(10,5)\energie=0 And grau(1,6)\energie=0 And grau(2,6)\energie=0  And grau(3,6)\energie=0 And grau(4,6)\energie=0 And grau(5,6)\energie=0 And grau(6,6)\energie=0 And grau(7,6)\energie=0 And grau(8,6)\energie=0 And grau(9,6)\energie=0 And grau(10,6)\energie=0 And grau(1,7)\energie=0 And grau(2,7)\energie=0  And grau(3,7)\energie=0 And grau(4,7)\energie=0 And grau(5,7)\energie=0 And grau(6,7)\energie=0 And grau(7,7)\energie=0 And grau(8,7)\energie=0 And grau(9,7)\energie=0 And grau(10,7)\energie=0 And grau(1,8)\energie=0 And grau(2,8)\energie=0  And grau(3,8)\energie=0 And grau(4,8)\energie=0 And grau(5,8)\energie=0 And grau(6,8)\energie=0 And grau(7,8)\energie=0 And grau(8,8)\energie=0 And grau(9,8)\energie=0 And grau(10,8)\energie=0 Then
Goto ende
EndIf





;der Ball

xco=xco+m
yco=yco+n

If xco>=630   Then m=-m
If yco>=470 Then Goto ende
If xco<=10   Then m=-m
If yco<=10   Then n=-n



;Kollision mit dem Brett

If ImagesOverlap(BALL, XCO,yco,brett,rechts,460) n=-n











;Ball zeigen

DrawImage ball,xco,yco









Flip
Wend



;das dicke Ende
;alles Suber machen
.ende
Color 255,0,0
Cls
SetBuffer FrontBuffer()
Cls
SetBuffer BackBuffer()
Cls
SetBuffer FrontBuffer()
Cls


;Nochmal??????????

While Not KeyHit(1)



Text 320,50,"ENDE",1,1
Text 320,100,"Drücken sie Enter um noch mal zu spielen",1,1
Text 320,150,"und Esc um aufzuhören .",1,1

If KeyHit(28) Or KeyHit(156) Goto begin

Wend


;alles Suber machen

Cls
SetBuffer FrontBuffer()
Cls
SetBuffer BackBuffer()
Cls
SetBuffer FrontBuffer()
Cls

;Impressum

SetFont impacta
Text 320,100,"´Pong Bomb´",1,1

SetFont impactd
Text 320,150,"( hergestellt von Manuel Bellersen )",1,1

Text 320,250,"Ich hoffe es hat ihnen gefallen.",1,1
Text 320,300,"Schauen sie doch mal bei http://www.Xom-I-moX.dd.vu/",1,1
Text 320,350,"oder bei http://www.Xom-I-moX.de.vu/ vorbei .",1,1

SetFont impacta
Text 320,400,"Auf Wiedersehen !",1,1
Delay 10







;endgültig alles Suber machen

FreeFont impactc
FreeFont impactd
FreeFont impacta
FreeFont impactb
FreeImage block1
FreeImage brett

End
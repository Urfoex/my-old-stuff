;Hi
;Auf gehts
;mit Grafik und Titel

Graphics 640,480,16,1
AppTitle "Pong Bomb"
SetBuffer BackBuffer()

;dann wollen wir mal Laden

;Fonts

impacta=LoadFont("impact",60,1) 
impactb=LoadFont("impact",25,1)
impactc=LoadFont("impact",34,1)
impactd=LoadFont("impact",24)

;Grafiken

block=LoadAnimImage("Grafik/stein1.bmp",53,20,0,4)
brett=LoadImage("Grafik/brett.bmp")
ball=LoadImage("Grafik/ball.bmp")



;Textfarbe 
Color 255,0,0


;die goldene Mitte

MidHandle brett
MidHandle ball


;durchsichtige Bilder

MaskImage brett,192,192,192
MaskImage ball,192,192,192

;Hier gehts los mit dem Anfangsbild

While Not KeyHit(28) Or KeyHit(156)


Flip
SetFont impacta
Text 320,50,"Hallo",1,1

SetFont impactb
Text 320,150,"Sie wollen also ´Pong Bomb´ spielen ?",1,1

SetFont impactc
Text 320,300,"Gut !",1,1

SetFont impactd
Text 320,400,"Drücken sie Enter um zu beginnen .",1,1


Wend


;Typen definition

Type stein
  Field art
  Field energie
  Field x
  Field y
End Type







Cls
Flip

SetBuffer BackBuffer()
SetBuffer FrontBuffer()
SetBuffer BackBuffer()
Include "misc/start.bb"







End
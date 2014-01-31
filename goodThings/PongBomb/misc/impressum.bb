Graphics 640,480,16,2
SetBuffer FrontBuffer()

impacta=LoadFont("impact",60,1) 
impactb=LoadFont("impact",25,1)
impactc=LoadFont("impact",34,1)
impactd=LoadFont("impact",24)


Color 255,0,0


SetFont impacta
Text 320,100,"´Pong Bomb´",1,1

SetFont impactd
Text 320,150,"( hergestellt von Manuel Bellersen )",1,1

Text 320,250,"Ich hoffe es hat ihnen gefallen.",1,1
Text 320,300,"Schauen sie doch mal bei http://www.Xom-I-moX.dd.vu/",1,1
Text 320,350,"oder bei http://www.Xom-I-moX.de.vu/ vorbei .",1,1

SetFont impacta
Text 320,400,"Auf Wiedersehen !",1,1
Delay 10000


FreeFont impactc
FreeFont impactd
FreeFont impacta
FreeFont impactb


End
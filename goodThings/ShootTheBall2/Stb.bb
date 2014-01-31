AppTitle "Shoot the ball"
Graphics3D 640,480,16,1


backround=LoadImage("grafiken\back.png")
psin=LoadImage("grafiken\psin.png")
psinspi=LoadImage("grafiken\psinspi.png")

HidePointer

MaskImage psin,100,100,100
MaskImage psinspi,100,100,100
MaskImage backround,100,100,100

AntiAlias 1
Dither 1

Type Player
	Field name$=""
	Field punktegesamt=0
	Field punktemitte=0
	Field punkteausen=0
	Field daneben=0
	Field zeit=0
	Field leben=3
	Field schuss=0
End Type

Global punktestand
Global benoschus
Global zeit
Global username$
Global mauszeiger
Global mauszeiger2
Global trefferpu
Global trefferpu2
Global randschus
Global mitschus
Global danebenschus
Global f_b


Dim hss.Player(10)
Dim hssave.Player(10)

	For a=0 To 9
		hss(a)=New Player
	Next
	
	For d=0 To 9
		hssave(d)=New Player
	Next
	
f_b=30


If (FileType("hs.dat")=1)
	hsdat=OpenFile("hs.dat")
Else
	hsdat=WriteFile("hs.dat")
EndIf
CloseFile hsdat




While (1)

	TileBlock backround,0,0
	DrawImage psin,MouseX(),MouseY()
	DrawImage psinspi,MouseX(),MouseY()

	If MouseHit(1)
		If ImageRectOverlap(psinspi,MouseX(),MouseY(),143,17,321,64)
			startgame()
		ElseIf ImageRectOverlap(psinspi,MouseX(),MouseY(),143,87,321,64)
			multiplayer()
		ElseIf ImageRectOverlap(psinspi,MouseX(),MouseY(),143,157,321,64)
			optionen()
		ElseIf ImageRectOverlap(psinspi,MouseX(),MouseY(),143,227,321,64)
			hiscore()
		ElseIf ImageRectOverlap(psinspi,MouseX(),MouseY(),143,297,321,64)
			Exit
		EndIf
	EndIf
	Flip
	Cls
Wend

Delete Each Player
End

;----------------------------------------------Start des Games--------------------------------------------------
Function Startgame()

;LoadImage
	loadingimg=LoadImage("grafiken\load.png")
	ClsColor 0,0,0
	Cls
	DrawBlock loadingimg,165,125
	Flip
;-----Laden-----und-----Einstellen-----
	mauszeiger=LoadImage("grafiken\mauze.png")
	mauszeiger2=LoadImage("grafiken\mauze2.png")
	trefferpu=LoadImage("grafiken\treffer.png")
	trefferpu2=LoadImage("grafiken\treffer2.png")
	MidHandle mauszeiger
	MidHandle mauszeiger2
	MidHandle trefferpu
	MidHandle trefferpu2
	MaskImage mauszeiger,100,100,100
	MaskImage mauszeiger2,100,100,100
	MaskImage trefferpu,100,100,100
	MaskImage trefferpu2,100,100,100

	benoschus=0
	punktestand=0
	zeit=0
	randschus=0
	mitschus=0
	danebenschus=0




	Cls
	Flip
	ClsColor 0,0,0
	Color 255,255,255
	Cls
	username$=""
	While (username$<1)
		Locate 200,240
		username$=Input("Geben sie bitte ihren Namen ein: ")
	Wend

	spieler.Player=New Player
	spieler\name$=username$




	Cls
	Flip
	Cls
	Locate 200,200
	Print "Start in 3..."
	Delay 1000

	Locate 200,215
	Print "         2..."
	Delay 1000

	Locate 200,230
	Print "         1..."
	Delay 1000

	Locate 200,250
	Print "   ! GO !   "
	Delay 1000
	Cls
	Flip
	Cls

	FlushMouse
	FlushKeys

	level1()


;free image
;free anything
	FlushMouse
	FlushKeys

;schreiben der hs in hs :D
	spieler.Player=First Player
	spieler\punktegesamt=punktestand
	spieler\schuss=benoschus
	spieler\zeit=zeit
	spieler\punkteausen=randschus
	spieler\punktemitte=mitschus
	spieler\daneben=danebenschus
;--------------------------------------------------------------------------------------------------------------------------------------------------------------------
;---------------------------------------------------------!!! ACHTUNG !!!--------------------------------------------------------------------------------------------
;--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	spieler\leben=0

	hsschreiben()


End Function

;----------------------------------------------Zeit--------------------------------------------------
Function Zeit(zeitstart,zeitende)
	zeit3=(zeitende-zeitstart)/1000
	Return zeit3
End Function

;----------------------------------------------hsschreiben--------------------------------------------------
Function hsschreiben()


End Function

;----------------------------------------------Start der Highscore--------------------------------------------------
Function hiscore()
	FlushMouse
	FlushKeys


	While Not KeyHit(1)
	ClsColor 255,255,255
	Cls
	Color 0,0,0
	
	Text 320,200,hss(a)\name$+hss(a)\punktegesamt+hss(a)\schuss+hss(a)\zeit+hss(a)\punkteausen+hss(a)\punktemitte+hss(a)\daneben+hss(a)\leben,1,1
	Text 320,460,"ESC drücken um ins Menü zu gelangen",1,1

	Flip

	Wend

	FlushKeys
	FlushMouse
End Function

;----------------------------------------------Multiplayer--------------------------------------------------
Function multiplayer()
	FlushMouse
	FlushKeys


	While Not KeyHit(1)
	ClsColor 255,255,255
	Cls
	Color 0,0,0
	Text 320,140,"Multiplayer zur Zeit nicht verfügbar",1,1
	Text 320,460,"ESC drücken um ins Menü zu gelangen",1,1

	Flip

	Wend

	FlushKeys
	FlushMouse
End Function

;----------------------------------------------Optionen--------------------------------------------------
Function optionen()
	FlushMouse
	FlushKeys

	While Not KeyHit(1)
	ClsColor 255,255,255
	Cls
	Color 0,0,0

	Text 320,240,"Optionen zur Zeit nicht verfügbar",1,1
	Text 320,460,"ESC drücken um ins Menü zu gelangen",1,1

	Flip


	Wend

	FlushKeys
	FlushMouse

End Function

;----------------------------------------------Level 1--------------------------------------------------
Function Level1()

	trefx=Rand(20,635)
	trefy=Rand(20,475)
	nachstufe=0
	zeitstart=MilliSecs()
	fps_begrenzung=CreateTimer(f_b)
	While Not KeyHit(1)

		ClsColor 0,0,0
		Cls



		DrawImage trefferpu2,trefx,trefy
		DrawImage trefferpu,trefx,trefy

		DrawImage mauszeiger,MouseX(),MouseY()
		DrawImage mauszeiger2,MouseX(),MouseY()


		If MouseHit(1)
			benoschus=benoschus+1
			If ImagesCollide(mauszeiger2,MouseX(),MouseY(),0,trefferpu,trefx,trefy,0)
				punktestand=punktestand+2
				mitschus=mitschus+1
				nachstufe=1
			Else If ImagesCollide(mauszeiger2,MouseX(),MouseY(),0,trefferpu2,trefx,trefy,0)
				punktestand=punktestand+1
				randschus=randschus+1
				nachstufe=1
			Else
				danebenschus=danebenschus+1
			EndIf
		EndIf


		zeitende=MilliSecs()
		zeit=zeit(zeitstart,zeitende)

		If nachstufe=1
			nachstufe=0
			trefx=Rand(20,635)
			trefy=Rand(20,475)
		EndIf



		Color 255,255,255
		Text 0,0,"Punktestand: " +punktestand,0,0
		Text 160,0,"Schuß benötigt: " +benoschus,0,0
		Text 340,0,"Zeit benötigt: " +zeit +"s",0,0
		WaitTimer fps_begrenzung
		Flip
	Wend
End Function

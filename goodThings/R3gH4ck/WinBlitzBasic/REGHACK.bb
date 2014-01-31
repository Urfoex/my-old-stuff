AppTitle "REGHACK"
Graphics 400,400,16,2
SetBuffer BackBuffer()
;----------------------------------------------------------------------------------------------------
schrift1=LoadFont("Fixedsys",15,1)
schrift2=LoadFont("Fixedsys",8,0)
ohack=LoadImage("11.png")
mhack=LoadImage("22.png")
logo=LoadImage("logo.png")
;----------------------------------------------------------------------------------------------------
ResizeImage ohack,20,20
ResizeImage mhack,30,30
;----------------------------------------------------------------------------------------------------
ClsColor 0,0,0
Color 255,0,0
Cls
;----------------------------------------------------------------------------------------------------
bild1=1

reghack=WriteFile("reghack.reg")
bild1=1
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
;----------------------------------------------------------------------------------------------------
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------
If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Ausführen im Startmenü",0,0
Text 15,300,"1/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf

;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1

WriteLine reghack,"REGEDIT4"
WriteLine reghack,""
WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoRun"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Beenden im Startmenü",0,0
Text 15,300,"2/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoClose"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------

Text 15,240,"Bildschirmänderungen verbieten",0,0
Text 15,300,"3/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoDispSettingsPageChr"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Bildschirmschoner",0,0
Text 15,260,"veränderen verbieten",0,0
Text 15,300,"4/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoDispScrSavPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Hintergrund ändern verbieten",0,0
Text 15,300,"5/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoDispBackgroundPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Suchen im Startmenü",0,0
Text 15,300,"6/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoFind"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Keine Systemsteuerung",0,0
Text 15,300,"7/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoDispCPL"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein einwählen ins Intenert",0,0
Text 15,300,"8/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Polices\Network]"
WriteLine reghack,Chr$(34)+"NoDialIn"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Keine Dokumente",0,0
Text 15,260,"in der Startleiste",0,0
Text 15,300,"9/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoRecentDocsMenu"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Menü des Startmenüs abschalten",0,0
Text 15,300,"10/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoChangeStartMenu"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Keine DOS-Anwendung ausführen",0,0
Text 15,300,"11/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp]"
WriteLine reghack,Chr$(34)+"Disabled"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1

;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Single DOS-Modus",0,0
Text 15,300,"12/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\WinOldApp]"
WriteLine reghack,Chr$(34)+"NoRealMode"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Drucker löschen verbieten",0,0
Text 15,300,"13/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Polices\Explorer]"
WriteLine reghack,Chr$(34)+"NoDeletePrinter"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Modul Kennwörter ausblenden",0,0
Text 15,300,"14/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoSecCPL"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Netzwerk-Modul ausblenden",0,0
Text 15,300,"15/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Network]"
WriteLine reghack,Chr$(34)+"NoNetSetup"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Identifikartions Modul",0,0
Text 15,260,"ausblenden",0,0
Text 15,300,"16/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Network]"
WriteLine reghack,Chr$(34)+"NoNetSetupIDPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Zugriffssteuerung",0,0
Text 15,260,"des Netzwerks fehlt",0,0
Text 15,300,"17/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Network]"
WriteLine reghack,Chr$(34)+"NoNetSetupSecurityPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Explorer ohne Ordneroptionen",0,0
Text 15,300,"18/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer]"
WriteLine reghack,Chr$(34)+"NoFolderOptions"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Gerätemanager",0,0
Text 15,300,"19/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoDevMgrPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Hardware Modul ausblenden",0,0
Text 15,300,"20/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoConfigPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Dateisystem aus System",0,0
Text 15,260,"entfernen",0,0
Text 15,300,"21/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoFileSysPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Virtueller Arbeitsspeicher",0,0
Text 15,260,"aus System entfernen",0,0
Text 15,300,"22/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoVirtMemPage"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Task Manager",0,0
Text 15,300,"23/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"DisableTaskManager"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Dateimenü",0,0
Text 15,300,"24/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoFileMenu"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Ordner aus Startmenü",0,0
Text 15,260,"und Explorer entfernen",0,0
Text 15,300,"25/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoSetFolders"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------

While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

If MouseX()>340 And MouseX()<360 Then
 maus=1
Else maus=0
EndIf
;----------------------------------------------------------------------------------------------------


Text 15,240,"Kein Context Menü",0,0
Text 15,300,"26/26",0,0
If maus=1 And MouseY()>236 And MouseY()<256 And MouseHit(1) Then 
 bild1=-bild1
EndIf

If bild1=1 Then
 DrawBlock ohack,340,239
ElseIf bild1=-1 Then
 DrawImage mhack,340,231
EndIf



;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um weiter zu machen ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
If bild1=1 a=0
If bild1=-1 a=1


WriteLine reghack,"[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System]"
WriteLine reghack,Chr$(34)+"NoViewContextMenu"+Chr$(34)+"= dword:0000000"+a
WriteLine reghack,""
bild1=1
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
While Not KeyHit(28)
Cls
SetFont schrift1
DrawBlock logo,0,0
;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------


Text 15,240,"Als nächsts müssen sie die Frage",0,0
Text 15,280,"des hinzufügens der Registrierung",0,0
Text 15,300,"mit JA beantworten !",0,0

Text 15,320,"Diese Fenster schließt automatisch !",0,0

;----------------------------------------------------------------------------------------------------
Text 20,340,"Drücke ENTER um zu enden ...",0,0

SetFont schrift2
Text 0,385," © 2003 coded Kakarott2003 | graphics Gokukiller"
Flip
Wend
;----------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------
CloseFile reghack
ExecFile "reghack.reg"
Delay 5000
DeleteFile "reghack.reg"
FreeImage ohack
FreeImage mhack
FreeImage logo
FreeFont schrift1
FreeFont schrieft2
;----------------------------------------------------------------------------------------------------
End
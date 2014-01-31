# Microsoft Developer Studio Generated NMAKE File, Based on R3gH4ck.dsp
!IF "$(CFG)" == ""
CFG=R3gH4ck - Win32 Debug
!MESSAGE Keine Konfiguration angegeben. R3gH4ck - Win32 Debug wird als Standard verwendet.
!ENDIF 

!IF "$(CFG)" != "R3gH4ck - Win32 Release" && "$(CFG)" != "R3gH4ck - Win32 Debug"
!MESSAGE UngÅltige Konfiguration "$(CFG)" angegeben.
!MESSAGE Sie kînnen beim AusfÅhren von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "R3gH4ck.mak" CFG="R3gH4ck - Win32 Debug"
!MESSAGE 
!MESSAGE FÅr die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "R3gH4ck - Win32 Release" (basierend auf  "Win32 (x86) Application")
!MESSAGE "R3gH4ck - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE 
!ERROR Eine ungÅltige Konfiguration wurde angegeben.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "R3gH4ck - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\R3gH4ck.exe"


CLEAN :
	-@erase "$(INTDIR)\R3gH4ck.obj"
	-@erase "$(INTDIR)\R3gH4ck.pch"
	-@erase "$(INTDIR)\R3gH4ck.res"
	-@erase "$(INTDIR)\R3gH4ckDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\R3gH4ck.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\R3gH4ck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\R3gH4ck.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\R3gH4ck.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\R3gH4ck.pdb" /machine:I386 /out:"$(OUTDIR)\R3gH4ck.exe" 
LINK32_OBJS= \
	"$(INTDIR)\R3gH4ck.obj" \
	"$(INTDIR)\R3gH4ckDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\R3gH4ck.res"

"$(OUTDIR)\R3gH4ck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "R3gH4ck - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\R3gH4ck.exe"


CLEAN :
	-@erase "$(INTDIR)\R3gH4ck.obj"
	-@erase "$(INTDIR)\R3gH4ck.pch"
	-@erase "$(INTDIR)\R3gH4ck.res"
	-@erase "$(INTDIR)\R3gH4ckDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\R3gH4ck.exe"
	-@erase "$(OUTDIR)\R3gH4ck.ilk"
	-@erase "$(OUTDIR)\R3gH4ck.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\R3gH4ck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\R3gH4ck.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\R3gH4ck.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\R3gH4ck.pdb" /debug /machine:I386 /out:"$(OUTDIR)\R3gH4ck.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\R3gH4ck.obj" \
	"$(INTDIR)\R3gH4ckDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\R3gH4ck.res"

"$(OUTDIR)\R3gH4ck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("R3gH4ck.dep")
!INCLUDE "R3gH4ck.dep"
!ELSE 
!MESSAGE Warning: cannot find "R3gH4ck.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "R3gH4ck - Win32 Release" || "$(CFG)" == "R3gH4ck - Win32 Debug"
SOURCE=.\R3gH4ck.cpp

"$(INTDIR)\R3gH4ck.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\R3gH4ck.pch"


SOURCE=.\R3gH4ck.rc

"$(INTDIR)\R3gH4ck.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\R3gH4ckDlg.cpp

"$(INTDIR)\R3gH4ckDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\R3gH4ck.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "R3gH4ck - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\R3gH4ck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\R3gH4ck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "R3gH4ck - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\R3gH4ck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\R3gH4ck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 


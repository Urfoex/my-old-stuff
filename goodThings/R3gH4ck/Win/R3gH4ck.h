// R3gH4ck.h : Haupt-Header-Datei f�r die Anwendung R3GH4CK
//

#if !defined(AFX_R3GH4CK_H__B075C0BA_A904_11D8_A136_00C0267580E3__INCLUDED_)
#define AFX_R3GH4CK_H__B075C0BA_A904_11D8_A136_00C0267580E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CR3gH4ckApp:
// Siehe R3gH4ck.cpp f�r die Implementierung dieser Klasse
//

class CR3gH4ckApp : public CWinApp
{
public:
	CR3gH4ckApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CR3gH4ckApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CR3gH4ckApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_R3GH4CK_H__B075C0BA_A904_11D8_A136_00C0267580E3__INCLUDED_)

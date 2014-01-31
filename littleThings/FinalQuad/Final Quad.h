// Final Quad.h : Haupt-Header-Datei für die Anwendung FINAL QUAD
//

#if !defined(AFX_FINALQUAD_H__595C74A2_55A0_11D9_AF35_00A0C944FB63__INCLUDED_)
#define AFX_FINALQUAD_H__595C74A2_55A0_11D9_AF35_00A0C944FB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CFinalQuadApp:
// Siehe Final Quad.cpp für die Implementierung dieser Klasse
//

class CFinalQuadApp : public CWinApp
{
public:
	CFinalQuadApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CFinalQuadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CFinalQuadApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_FINALQUAD_H__595C74A2_55A0_11D9_AF35_00A0C944FB63__INCLUDED_)

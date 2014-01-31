// WSSW.h : Haupt-Header-Datei für die Anwendung WSSW
//

#if !defined(AFX_WSSW_H__ADF0A3C2_B106_11DA_A530_00A0C944FB63__INCLUDED_)
#define AFX_WSSW_H__ADF0A3C2_B106_11DA_A530_00A0C944FB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CWSSWApp:
// Siehe WSSW.cpp für die Implementierung dieser Klasse
//

class CWSSWApp : public CWinApp
{
public:
	CWSSWApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CWSSWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CWSSWApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_WSSW_H__ADF0A3C2_B106_11DA_A530_00A0C944FB63__INCLUDED_)

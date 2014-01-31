// Final QuadDlg.h : Header-Datei
//

#if !defined(AFX_FINALQUADDLG_H__595C74A4_55A0_11D9_AF35_00A0C944FB63__INCLUDED_)
#define AFX_FINALQUADDLG_H__595C74A4_55A0_11D9_AF35_00A0C944FB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFinalQuadDlg Dialogfeld

class CFinalQuadDlg : public CDialog
{
// Konstruktion
public:
	CString m_Inv1;
	CString m_Inv2;
	CString m_Inv3;
	CString m_Inv4;
	CString m_Inv5;
	CString m_Inv6;
	CString m_Inv7;
	CString m_Inv8;
	CString m_Inv9;
	CString m_Inv10;
	CString m_Gegenstand;
	short int m_Z;
	short int m_Y;
	short int m_X;
	CFinalQuadDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CFinalQuadDlg)
	enum { IDD = IDD_FINALQUAD_DIALOG };
	CString	m_Textfeld;
	CString	m_Eingabe;
	CString	m_Taetigkeit;
	short m_Xt;
	short m_Yt;
	short m_Zt;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CFinalQuadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CFinalQuadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInventar();
	afx_msg void Onfertig();
	afx_msg void Onlinks();
	afx_msg void Onvor();
	afx_msg void Onhoch();
	afx_msg void Onzurueck();
	afx_msg void Onrunter();
	afx_msg void Onrechts();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_FINALQUADDLG_H__595C74A4_55A0_11D9_AF35_00A0C944FB63__INCLUDED_)

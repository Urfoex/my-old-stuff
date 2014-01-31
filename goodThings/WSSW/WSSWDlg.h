// WSSWDlg.h : Header-Datei
//

#if !defined(AFX_WSSWDLG_H__ADF0A3C4_B106_11DA_A530_00A0C944FB63__INCLUDED_)
#define AFX_WSSWDLG_H__ADF0A3C4_B106_11DA_A530_00A0C944FB63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWSSWDlg Dialogfeld

class CWSSWDlg : public CDialog
{
// Konstruktion
public:
	int iCZ;
	int iZ;
	bool bMC;
	CWSSWDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CWSSWDlg)
	enum { IDD = IDD_WSSW_DIALOG };
	int	m_HolzAnzahl;
	int	m_cz;
	int	m_sz;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CWSSWDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CWSSWDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMensch();
	afx_msg void OnComputer();
	afx_msg void Onstart();
	afx_msg void Onh1();
	afx_msg void Onh2();
	afx_msg void Onh3();
	afx_msg void Onziehen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_WSSWDLG_H__ADF0A3C4_B106_11DA_A530_00A0C944FB63__INCLUDED_)

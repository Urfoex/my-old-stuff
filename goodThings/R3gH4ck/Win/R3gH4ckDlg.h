// R3gH4ckDlg.h : Header-Datei
//

#if !defined(AFX_R3GH4CKDLG_H__B075C0BC_A904_11D8_A136_00C0267580E3__INCLUDED_)
#define AFX_R3GH4CKDLG_H__B075C0BC_A904_11D8_A136_00C0267580E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CR3gH4ckDlg Dialogfeld

class CR3gH4ckDlg : public CDialog
{
// Konstruktion
public:
	int iNeustart;
	CR3gH4ckDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CR3gH4ckDlg)
	enum { IDD = IDD_R3GH4CK_DIALOG };
	BOOL	m_kais;
	BOOL	m_kbis;
	BOOL	m_bav;
	BOOL	m_bsvv;
	BOOL	m_kdis;
	BOOL	m_keii;
	BOOL	m_ksis;
	BOOL	m_kss;
	BOOL	m_hvv;
	BOOL	m_mdsa;
	BOOL	m_kdaa;
	BOOL	m_ksdm;
	BOOL	m_kdl;
	BOOL	m_mka;
	BOOL	m_nma;
	BOOL	m_ima;
	BOOL	m_zdnf;
	BOOL	m_eoo;
	BOOL	m_kgm;
	BOOL	m_hma;
	BOOL	m_dsase;
	BOOL	m_vau;
	BOOL	m_ktm;
	BOOL	m_kdm;
	BOOL	m_koisue;
	BOOL	m_kcm;
	BOOL	m_krae;
	BOOL	m_ktle;
	BOOL	m_dlbsl;
	BOOL	m_kssis;
	BOOL	m_kds;
	BOOL	m_kes;
	BOOL	m_kkae;
	BOOL	m_kbp;
	BOOL	m_kb;
	BOOL	m_kg;
	BOOL	m_kzs;
	BOOL	m_kdf;
	BOOL	m_kdrf;
	BOOL	m_knwlw;
	BOOL	m_kiad;
	BOOL	m_daev;
	BOOL	m_kisad;
	CString	m_exptit;
	BOOL	m_lna;
	BOOL	m_ensb;
	BOOL	m_krkie;
	BOOL	m_ktoie;
	BOOL	m_ksuie;
	BOOL	m_kfvo;
	BOOL	m_kdneu;
	BOOL	m_kdopen;
	BOOL	m_kfind;
	BOOL	m_kdzaw;
	BOOL	m_kfsie;
	BOOL	m_kdhf;
	BOOL	m_kcdar;
	BOOL	m_bbf;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CR3gH4ckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CR3gH4ckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNehmen();
	virtual void OnOK();
	afx_msg void Onrfs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_R3GH4CKDLG_H__B075C0BC_A904_11D8_A136_00C0267580E3__INCLUDED_)

// R3gH4ckDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "R3gH4ck.h"
#include "R3gH4ckDlg.h"
#include <iostream.h>
#include <fstream.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CR3gH4ckDlg Dialogfeld

CR3gH4ckDlg::CR3gH4ckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CR3gH4ckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CR3gH4ckDlg)
	m_kais = FALSE;
	m_kbis = FALSE;
	m_bav = FALSE;
	m_bsvv = FALSE;
	m_kdis = FALSE;
	m_keii = FALSE;
	m_ksis = FALSE;
	m_kss = FALSE;
	m_hvv = FALSE;
	m_mdsa = FALSE;
	m_kdaa = FALSE;
	m_ksdm = FALSE;
	m_kdl = FALSE;
	m_mka = FALSE;
	m_nma = FALSE;
	m_ima = FALSE;
	m_zdnf = FALSE;
	m_eoo = FALSE;
	m_kgm = FALSE;
	m_hma = FALSE;
	m_dsase = FALSE;
	m_vau = FALSE;
	m_ktm = FALSE;
	m_kdm = FALSE;
	m_koisue = FALSE;
	m_kcm = FALSE;
	m_krae = FALSE;
	m_ktle = FALSE;
	m_dlbsl = FALSE;
	m_kssis = FALSE;
	m_kds = FALSE;
	m_kes = FALSE;
	m_kkae = FALSE;
	m_kbp = FALSE;
	m_kb = FALSE;
	m_kg = FALSE;
	m_kzs = FALSE;
	m_kdf = FALSE;
	m_kdrf = FALSE;
	m_knwlw = FALSE;
	m_kiad = FALSE;
	m_daev = FALSE;
	m_kisad = FALSE;
	m_exptit = _T("");
	m_lna = FALSE;
	m_ensb = FALSE;
	m_krkie = FALSE;
	m_ktoie = FALSE;
	m_ksuie = FALSE;
	m_kfvo = FALSE;
	m_kdneu = FALSE;
	m_kdopen = FALSE;
	m_kfind = FALSE;
	m_kdzaw = FALSE;
	m_kfsie = FALSE;
	m_kdhf = FALSE;
	m_kcdar = FALSE;
	m_bbf = FALSE;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CR3gH4ckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CR3gH4ckDlg)
	DDX_Check(pDX, IDC_kais, m_kais);
	DDX_Check(pDX, IDC_kbis, m_kbis);
	DDX_Check(pDX, IDC_bav, m_bav);
	DDX_Check(pDX, IDC_bsvv, m_bsvv);
	DDX_Check(pDX, IDC_kdis, m_kdis);
	DDX_Check(pDX, IDC_keii, m_keii);
	DDX_Check(pDX, IDC_ksis, m_ksis);
	DDX_Check(pDX, IDC_kss, m_kss);
	DDX_Check(pDX, IDC_hvv, m_hvv);
	DDX_Check(pDX, IDC_mdsa, m_mdsa);
	DDX_Check(pDX, IDC_kdaa, m_kdaa);
	DDX_Check(pDX, IDC_ksdm, m_ksdm);
	DDX_Check(pDX, IDC_kdl, m_kdl);
	DDX_Check(pDX, IDC_mka, m_mka);
	DDX_Check(pDX, IDC_nma, m_nma);
	DDX_Check(pDX, IDC_ima, m_ima);
	DDX_Check(pDX, IDC_zdnf, m_zdnf);
	DDX_Check(pDX, IDC_eoo, m_eoo);
	DDX_Check(pDX, IDC_kgm, m_kgm);
	DDX_Check(pDX, IDC_hma, m_hma);
	DDX_Check(pDX, IDC_dsase, m_dsase);
	DDX_Check(pDX, IDC_vau, m_vau);
	DDX_Check(pDX, IDC_ktm, m_ktm);
	DDX_Check(pDX, IDC_kdm, m_kdm);
	DDX_Check(pDX, IDC_koisue, m_koisue);
	DDX_Check(pDX, IDC_kcm, m_kcm);
	DDX_Check(pDX, IDC_krae, m_krae);
	DDX_Check(pDX, IDC_ktle, m_ktle);
	DDX_Check(pDX, IDC_dlbsl, m_dlbsl);
	DDX_Check(pDX, IDC_kssis, m_kssis);
	DDX_Check(pDX, IDC_kds, m_kds);
	DDX_Check(pDX, IDC_kes, m_kes);
	DDX_Check(pDX, IDC_kkae, m_kkae);
	DDX_Check(pDX, IDC_kbp, m_kbp);
	DDX_Check(pDX, IDC_kb, m_kb);
	DDX_Check(pDX, IDC_kg, m_kg);
	DDX_Check(pDX, IDC_kzs, m_kzs);
	DDX_Check(pDX, IDC_kdf, m_kdf);
	DDX_Check(pDX, IDC_kdrf, m_kdrf);
	DDX_Check(pDX, IDC_knwlw, m_knwlw);
	DDX_Check(pDX, IDC_kiad, m_kiad);
	DDX_Check(pDX, IDC_daev, m_daev);
	DDX_Check(pDX, IDC_kisad, m_kisad);
	DDX_Text(pDX, IDC_exptit, m_exptit);
	DDX_Check(pDX, IDC_lna, m_lna);
	DDX_Check(pDX, IDC_ensb, m_ensb);
	DDX_Check(pDX, IDC_krkie, m_krkie);
	DDX_Check(pDX, IDC_ktoie, m_ktoie);
	DDX_Check(pDX, IDC_ksuie, m_ksuie);
	DDX_Check(pDX, IDC_kfvo, m_kfvo);
	DDX_Check(pDX, IDC_kdneu, m_kdneu);
	DDX_Check(pDX, IDC_kdopen, m_kdopen);
	DDX_Check(pDX, IDC_kfind, m_kfind);
	DDX_Check(pDX, IDC_kdzaw, m_kdzaw);
	DDX_Check(pDX, IDC_kfsie, m_kfsie);
	DDX_Check(pDX, IDC_kdhf, m_kdhf);
	DDX_Check(pDX, IDC_kcdar, m_kcdar);
	DDX_Check(pDX, IDC_bbf, m_bbf);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CR3gH4ckDlg, CDialog)
	//{{AFX_MSG_MAP(CR3gH4ckDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDNEHMEN, OnNehmen)
	ON_BN_CLICKED(IDC_rfs, Onrfs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CR3gH4ckDlg Nachrichten-Handler

BOOL CR3gH4ckDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CR3gH4ckDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CR3gH4ckDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CR3gH4ckDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CR3gH4ckDlg::OnNehmen() 
{
	WinExec ("regedit /s reghack.reg" , SW_SHOW);
}

void CR3gH4ckDlg::OnOK() 
{
	iNeustart = MessageBox("TIP: Drücken sie auf START -> BEENDEN. Halten sie nun die SHIFT-Taste gedrückt und starten sie neu (dadurch wird nur Windows neugestartet und nicht der ganze Rechner, was den Bootprozess um ca die Hälfte verkürzt). Sobald ´Windows wird neu gestartet` erscheint, können sie die Shift-Taste wieder los lassen.","Sie müssen neustarten, damit alle Änderungen aktiv werden !",MB_OK | MB_ICONEXCLAMATION);
	if (iNeustart==IDOK)
	{
		CDialog::OnOK();
	}
	else
		CDialog::OnOK();
}

void CR3gH4ckDlg::Onrfs() 
{
	UpdateData(true);

	ofstream o_Reghack("reghack.reg");// Datei öffnen
	o_Reghack << "REGEDIT4" << endl << endl;
	o_Reghack << "[HKEY_CURRENT_USER\\Software\\R3gH4ck]" << endl ;
	o_Reghack << "\"Version\"=\"3.0\"" << endl ;
	o_Reghack << "\"Hersteller\"=\"Manuel Bellersen\"" << endl ;
	o_Reghack << "\"Datum\"=\"2004\"" << endl ;
	o_Reghack << "\"eMail\"=\"Kakarott2003@yahoo.de\"" << endl << endl ;
	
	// kein ausführen
	o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl ;
	o_Reghack << "\"NoRun\"= dword:0000000"<< m_kais << endl ;
	// kein beenden
	o_Reghack << "\"NoClose\"= dword:0000000"<< m_kbis << endl ;
	// kein suchen
	o_Reghack << "\"NoFind\"= dword:0000000"<< m_ksis << endl ;
	// kein dokumente
	o_Reghack << "\"NoRecentDocsMenu\"= dword:0000000"<< m_kdis << endl ;
	// kein menü
	o_Reghack << "\"NoChangeStartMenu\"= dword:0000000"<< m_mdsa << endl ;
	// kein drucker löschen
	o_Reghack << "\"NoDeletePrinter\"= dword:0000000"<< m_kdl << endl ;
	// kein explorer ohne options
	o_Reghack << "\"NoFolderOptions\"= dword:0000000"<< m_eoo << endl ;
	// kein regedit
	o_Reghack << "\"DisableRegistryTools\"= dword:0000000"<< m_krae << endl ;

	o_Reghack << "[HKEY_USERS\\.DEFAULT\\Software\\Microsoft\\WindowsNT\\CurrentVersion\\Policies\\System]" << endl ;
	o_Reghack << "\"DisableRegistryTools\"= dword:0000000"<< m_krae << endl ;
	o_Reghack << "[HKEY_USERS\\.DEFAULT\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl ;
	o_Reghack << "\"DisableRegistryTools\"= dword:0000000"<< m_krae << endl ;
	o_Reghack << "[HKEY_USERS\\.DEFAULT\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl ;
	o_Reghack << "\"DisableRegistryTools\"= dword:0000000"<< m_krae << endl ;
	o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl ;
	o_Reghack << "\"DisableRegistryTools\"= dword:0000000"<< m_krae << endl ;

	// keine Taskleisteneinstellung
	o_Reghack << "\"NoSetTaskbar\"= dword:0000000"<< m_ktle << endl ;
	// dokumente löschen
	o_Reghack << "\"ClearRecentDocsOnExit\"= dword:0000000"<< m_dlbsl << endl ;
	// keine systeme im start
	o_Reghack << "\"NoSetFolders\"= dword:0000000"<< m_kssis << endl ;
	// laufwerke anzeigen
	if (m_lna==true)
		o_Reghack << "\"NoDrives\"= dword:03ffffff"<< endl ;
	else
		o_Reghack << "\"NoDrives\"= dword:00000000"<< endl ;
	// netzlaufwerk
	o_Reghack << "\"NoNetHood\"= dword:0000000"<< m_knwlw << endl ;
	// inet auf desk
	o_Reghack << "\"Nolnternetlcon\"= dword:0000000"<< m_kiad << endl ;
	// desk ändern
	o_Reghack << "\"NoSaveSettings\"= dword:0000000"<< m_daev << endl ;
	// desk icons
	o_Reghack << "\"NoDesktop\"= dword:0000000"<< m_kisad << endl ;
	// add drucker
	o_Reghack << "\"NoAddPrinter\"= dword:0000000"<< m_kdhf << endl ;

	// Explo Title
	o_Reghack << endl << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Internet Explorer\\Main]" << endl;
	o_Reghack << "\"Window Title\"=\"" << m_exptit << "\""<< endl ;

	// schließen
	o_Reghack << endl << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
	o_Reghack << "\"NoRecentDocsMenu\"= dword:0000000"<< m_ensb << endl ;
	// rechtsklick
	o_Reghack << "\"NoBrowserContextMenu\"= dword:0000000"<< m_krkie << endl ;
	// optionen tools
	o_Reghack << "\"NoBrowserOptions\"= dword:0000000"<< m_ktoie << endl ;
	// save as
	o_Reghack << "\"NoBrowserSaveAs\"= dword:0000000"<< m_ksuie << endl ;
	// favs
	o_Reghack << "\"NoFavorites\"= dword:0000000"<< m_kfvo << endl ;
	// neu
	o_Reghack << "\"NoFileNew\"= dword:0000000"<< m_kdneu << endl ;
	// öffnen
	o_Reghack << "\"NoFileOpen\"= dword:0000000"<< m_kdopen << endl ;
	// finden
	o_Reghack << "\"NoFindFiles\"= dword:0000000"<< m_kfind << endl ;
	// download dir
	o_Reghack << "\"NoSelectDownloadDir\"= dword:0000000"<< m_kdzaw << endl ;
	// fullscreen
	o_Reghack << "\"NoTheaterMode\"= dword:0000000"<< m_kfsie << endl ;

	// autorun
	o_Reghack << endl << "[HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\CDRom]" << endl;
	o_Reghack << "\"Autorun\"= dword:0000000"<< m_kcdar << endl ;

	// beep 
	o_Reghack << endl << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Internet Explorer\\Main]" << endl;
	if (m_bbf==true)
		o_Reghack << "\"Beep\"=\"yes\"" << endl ;
	else
		o_Reghack << "\"Beep\"=\"no\"" << endl ;

	// keine bildschirmänderungen
	o_Reghack << endl << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl ;
	o_Reghack << "\"NoDispSettingsPageChr\"= dword:0000000"<< m_bav << endl ;
	// keine bildschirmschoneränderungen
	o_Reghack << "\"NoDispScrSavPage\"= dword:0000000"<< m_bsvv << endl ;
	// keine hintergrundänderungen
	o_Reghack << "\"NoDispBackgroundPage\"= dword:0000000"<< m_hvv << endl ;
	// keine systemsteuerung
	o_Reghack << "\"NoDispCPL\"= dword:0000000"<< m_kss << endl ;
	// keine kennwörter
	o_Reghack << "\"NoSecCPL\"= dword:0000000"<< m_mka << endl ;
	// kein gerätemanager
	o_Reghack << "\"NoDevMgrPage\"= dword:0000000"<< m_kgm << endl ;
	// kein hardwaremodul
	o_Reghack << "\"NoConfigPage\"= dword:0000000"<< m_hma << endl ;
	// kein dateisystem
	o_Reghack << "\"NoFileSysPage\"= dword:0000000"<< m_dsase << endl ;
	// kein virtu arbei
	o_Reghack << "\"NoVirtMemPage\"= dword:0000000"<< m_vau << endl ;
	// kein task manager
	o_Reghack << "\"DisableTaskManager\"= dword:0000000"<< m_ktm << endl ;
	// kein dateimenü
	o_Reghack << "\"NoFileMenu\"= dword:0000000"<< m_kdm << endl ;
	// kein ordner
	o_Reghack << "\"NoSetFolders\"= dword:0000000"<< m_koisue << endl ;
	// kein context
	o_Reghack << "\"NoViewContextMenu\"= dword:0000000"<< m_kcm << endl ;
	// kein darstellung
	o_Reghack << "\"NoDispAppearancePage\"= dword:0000000"<< m_kds << endl ;
	// kein einstellung
	o_Reghack << "\"NoDispSettingsPage\"= dword:0000000"<< m_kes << endl ;
	// kein kennwörter
	o_Reghack << "\"NoPwdPage\"= dword:0000000"<< m_kkae << endl ;
	// kein benutzerprof
	o_Reghack << "\"NoAdminPaqe\"= dword:0000000"<< m_kbp << endl ;
	// kein benutzer
	o_Reghack << "\"NoProfilePage\"= dword:0000000"<< m_kb << endl ;
	// kein geräte
	o_Reghack << "\"NoDevMgrPage\"= dword:0000000"<< m_kg << endl ;

	// kein internet
	o_Reghack << endl << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl ;
	o_Reghack << "\"NoDialIn\"= dword:0000000"<< m_keii << endl ;
	// kein netzwerk
	o_Reghack << "\"NoNetSetup\"= dword:0000000"<< m_nma << endl ;
	// kein identifikation
	o_Reghack << "\"NoNetSetupIDPage\"= dword:0000000"<< m_ima << endl ;
	// kein zugriffsteu
	o_Reghack << "\"NoNetSetupSecurityPage\"= dword:0000000"<< m_kzs << endl ;
	// kein dateifraigabe
	o_Reghack << "\"NoFileSharingControl\"= dword:0000000"<< m_kdf << endl ;
	// kein druckerfreigabe
	o_Reghack << "\"NoPrintSharing\"= dword:0000000"<< m_kdrf << endl ;

	// kein dos
	o_Reghack << endl << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl ;
	o_Reghack << "\"Disabled\"= dword:0000000"<< m_kdaa << endl ;
	// kein single-dos
	o_Reghack << "\"NoRealMode\"= dword:0000000"<< m_ksdm << endl ;
	// kein zugriffssteuerung
	o_Reghack << "\"NoNetSetupSecurityPage\"= dword:0000000"<< m_zdnf << endl ;

	o_Reghack.close();
}

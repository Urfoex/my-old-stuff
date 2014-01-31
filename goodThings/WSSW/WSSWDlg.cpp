// WSSWDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "WSSW.h"
#include "WSSWDlg.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWSSWDlg Dialogfeld

CWSSWDlg::CWSSWDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWSSWDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWSSWDlg)
	m_HolzAnzahl = 12;
	m_cz = 0;
	m_sz = 0;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWSSWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWSSWDlg)
	DDX_Text(pDX, IDC_holz, m_HolzAnzahl);
	DDX_Text(pDX, IDC_cz, m_cz);
	DDX_Text(pDX, IDC_sz, m_sz);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWSSWDlg, CDialog)
	//{{AFX_MSG_MAP(CWSSWDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Mensch, OnMensch)
	ON_BN_CLICKED(IDC_Computer, OnComputer)
	ON_BN_CLICKED(IDC_start, Onstart)
	ON_BN_CLICKED(IDC_h1, Onh1)
	ON_BN_CLICKED(IDC_h2, Onh2)
	ON_BN_CLICKED(IDC_h3, Onh3)
	ON_BN_CLICKED(IDC_ziehen, Onziehen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWSSWDlg Nachrichten-Handler

BOOL CWSSWDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CWSSWDlg::OnPaint() 
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
HCURSOR CWSSWDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWSSWDlg::OnMensch() 
{
	bMC=false;
}

void CWSSWDlg::OnComputer() 
{
	bMC=true;
}

void CWSSWDlg::Onstart() 
{
	UpdateData(true);
	if(bMC==false || bMC==true)
	{
	GetDlgItem(IDC_Mensch)->EnableWindow(false);
	GetDlgItem(IDC_Computer)->EnableWindow(false);
	if(bMC==false)
		MessageBox("Mensch fängt an.",MB_OK,MB_ICONINFORMATION);
	else
	{
		MessageBox("Computer fängt an.",MB_OK,MB_ICONINFORMATION);
		UpdateData(true);
		m_HolzAnzahl=m_HolzAnzahl-3;
		iCZ=3;
		m_cz=iCZ;
		UpdateData(false);
	}
	GetDlgItem(IDC_ziehen)->EnableWindow(true);
	GetDlgItem(IDC_h1)->EnableWindow(true);
	GetDlgItem(IDC_h2)->EnableWindow(true);
	GetDlgItem(IDC_h3)->EnableWindow(true);
	GetDlgItem(IDC_start)->EnableWindow(false);
	}
}

void CWSSWDlg::Onh1() 
{
	iZ=1;
}

void CWSSWDlg::Onh2() 
{
	iZ=2;
}

void CWSSWDlg::Onh3() 
{
	iZ=3;
}

void CWSSWDlg::Onziehen() 
{
	UpdateData(true);
	m_sz=iZ;
	m_HolzAnzahl=m_HolzAnzahl-iZ;
	if(m_HolzAnzahl<0)
		m_HolzAnzahl=0;
	UpdateData(false);
	
	switch(m_HolzAnzahl)
	{
	case 12:	m_HolzAnzahl=m_HolzAnzahl-3;
				iCZ=1;
				break;
	case 11:	m_HolzAnzahl=m_HolzAnzahl-2;
				iCZ=3;
				break;
	case 10:	m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=2;
				break;
	case 9:		m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=1;
				break;
	case 8:		m_HolzAnzahl=m_HolzAnzahl-3;
				iCZ=3;
				break;
	case 7:		m_HolzAnzahl=m_HolzAnzahl-2;
				iCZ=2;
				break;
	case 6:		m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=1;
				break;
	case 5:		m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=1;
				break;
	case 4:		m_HolzAnzahl=m_HolzAnzahl-3;
				iCZ=3;
				break;
	case 3:		m_HolzAnzahl=m_HolzAnzahl-2;
				iCZ=2;
				break;
	case 2:		m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=1;
				break;
	case 1:		m_HolzAnzahl=m_HolzAnzahl-1;
				iCZ=1;
				UpdateData(false);
				MessageBox("Computer zieht das letzte Hölzchen und verliert.",MB_OK,MB_ICONINFORMATION);
				break;
	case 0:		iCZ=0;
				UpdateData(false);
				MessageBox("Sie haben das letzte Hölzchen gezogen und verlieren somit.",MB_OK,MB_ICONINFORMATION);
				break;
	default:	m_HolzAnzahl=0;
				m_cz=0;
				m_sz=0;
				UpdateData(false);
				MessageBox("Irgendwas stimmt mit den Hölzchen nicht.",MB_OK,MB_ICONINFORMATION);
				m_HolzAnzahl=0;
				break;
	}
	m_cz=iCZ;
	if(m_HolzAnzahl==0)
	{
		GetDlgItem(IDC_Mensch)->EnableWindow(true);
		GetDlgItem(IDC_Computer)->EnableWindow(true);
		GetDlgItem(IDC_ziehen)->EnableWindow(false);
		GetDlgItem(IDC_h1)->EnableWindow(false);
		GetDlgItem(IDC_h2)->EnableWindow(false);
		GetDlgItem(IDC_h3)->EnableWindow(false);
		GetDlgItem(IDC_start)->EnableWindow(true);
		m_HolzAnzahl=12;
		m_cz=0;
		m_sz=0;
	}
	UpdateData(false);
}

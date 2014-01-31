// Final QuadDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "Final Quad.h"
#include "Final QuadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFinalQuadDlg Dialogfeld


class csGegestand
{
public:
	csGegenstandt();
	~cs Gegenstand();
private:
	int energy;

}

CString CheckPlace(int,int,int);

CFinalQuadDlg::CFinalQuadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFinalQuadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFinalQuadDlg)
	m_Textfeld = _T("");
	m_Eingabe = _T("");
	m_Taetigkeit = _T("");
	m_Xt = 1;
	m_Yt = 1;
	m_Zt = 1;
	m_X=1;
	m_Y=1;
	m_Z=1;
	m_Inv1=" ";
	m_Inv2=" ";
	m_Inv3=" ";
	m_Inv4=" ";
	m_Inv5=" ";
	m_Inv6=" ";
	m_Inv7=" ";
	m_Inv8=" ";
	m_Inv9=" ";
	m_Inv10=" ";
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Textfeld="\n\n\t\tHallo und herzlich Willkommen bei\n\t\t\t \"Final Quad\" !\n\n\n\nDu befindest dich gerade in deinem Zimmer vorm PC.Deine Mutter kommt rein und bittet dich den Muell raus zu bringen. Nach 5 Minuten stuerzt urploetzlich dein PC ab und du beschließt den Muell waerend des Neustarts raus zu bringen.\n\n\t\t\tAuf geht´s !";
	
}

void CFinalQuadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFinalQuadDlg)
	DDX_Text(pDX, IDC_Textfeld, m_Textfeld);
	DDX_Text(pDX, IDC_Eingabe, m_Eingabe);
	DDX_CBString(pDX, IDC_Taetigkeit, m_Taetigkeit);
	DDX_Text(pDX, IDC_X, m_Xt);
	DDX_Text(pDX, IDC_Y, m_Yt);
	DDX_Text(pDX, IDC_Z, m_Zt);
	//}}AFX_DATA_MAP

	m_Textfeld=CheckPlace(m_X,m_Y,m_Z);


	
}

BEGIN_MESSAGE_MAP(CFinalQuadDlg, CDialog)
	//{{AFX_MSG_MAP(CFinalQuadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Inventar, OnInventar)
	ON_BN_CLICKED(IDC_fertig, Onfertig)
	ON_BN_CLICKED(IDC_links, Onlinks)
	ON_BN_CLICKED(IDC_vor, Onvor)
	ON_BN_CLICKED(IDC_hoch, Onhoch)
	ON_BN_CLICKED(IDC_zurueck, Onzurueck)
	ON_BN_CLICKED(IDC_runter, Onrunter)
	ON_BN_CLICKED(IDC_rechts, Onrechts)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinalQuadDlg Nachrichten-Handler

BOOL CFinalQuadDlg::OnInitDialog()
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

void CFinalQuadDlg::OnPaint() 
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
HCURSOR CFinalQuadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFinalQuadDlg::OnInventar() 
{
	UpdateData(true);
	m_Textfeld="1) "+m_Inv1+"\n2) "+m_Inv2+"\n3) "+m_Inv3+"\n4) "+m_Inv4+"\n5) "+m_Inv5+"\n6) "+m_Inv6+"\n7) "+m_Inv7+"\n8) "+m_Inv8+"\n9) "+m_Inv9+"\n10) "+m_Inv10;
	UpdateData(false);
	
}

void CFinalQuadDlg::Onfertig() 
{
	UpdateData(true);
	m_Taetigkeit.MakeLower();
	m_Eingabe.MakeUpper();
	m_Gegenstand.MakeUpper();
	if(m_Taetigkeit=="")
	{
		m_Textfeld="\n\n\n\n\n\n\n\t\tSie haben keine Taetigkeit ausgewaehlt.";
		UpdateData(false);
	}
	else
	{
		if(m_Taetigkeit=="nehmen")
		{
			if(m_Eingabe=="" || m_Eingabe!=m_Gegenstand)
			{
				m_Textfeld="\n\n\n\n\n\n\n\t\tBitte Gegegenstand waehlen.";
				UpdateData(false);
			}
			else
			{
				if(m_Taetigkeit=="nehmen" && m_Eingabe==m_Gegenstand)
				{
					if(m_Inv1==" ")
					{
						m_Inv1=m_Gegenstand;
						m_Textfeld=m_Gegenstand+" auf 1";
						UpdateData(false);
					}
					else
					{
						if(m_Inv2==" ")
						{
							m_Inv2=m_Gegenstand;
							m_Textfeld=m_Gegenstand+" auf 2";
							UpdateData(false);
						}
						else
						{
							if(m_Inv3==" ")
							{
								m_Inv3=m_Gegenstand;
								m_Textfeld=m_Gegenstand+" auf 3";
								UpdateData(false);
							}
							else
							{
								if(m_Inv4==" ")
								{
									m_Inv4=m_Gegenstand;
									m_Textfeld=m_Gegenstand+" auf 4";
									UpdateData(false);
								}
								else
								{
									if(m_Inv5==" ")
									{
										m_Inv5=m_Gegenstand;
										m_Textfeld=m_Gegenstand+" auf 5";
										UpdateData(false);
									}
									else
									{
										if(m_Inv6==" ")
										{
											m_Inv6=m_Gegenstand;
											m_Textfeld=m_Gegenstand+" auf 6";
											UpdateData(false);
										}
										else
										{
											if(m_Inv7==" ")
											{
												m_Inv7=m_Gegenstand;
												m_Textfeld=m_Gegenstand+" auf 7";
												UpdateData(false);
											}
											else
											{
												if(m_Inv8==" ")
												{
													m_Inv8=m_Gegenstand;
													m_Textfeld=m_Gegenstand+" auf 8";
													UpdateData(false);
												}
												else
												{
													if(m_Inv9==" ")
													{
														m_Inv9=m_Gegenstand;
														m_Textfeld=m_Gegenstand+" auf 9";
														UpdateData(false);
													}
													else
													{
														if(m_Inv10==" ")
														{
															m_Inv10=m_Gegenstand;
															m_Textfeld=m_Gegenstand+" auf 10";
															UpdateData(false);
														}
														else
															m_Textfeld="\n\n\n\n\t\tSie haben kein Platz im Inventar.";
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				UpdateData(false);
			}
		}
		else
		{
			if(m_Taetigkeit=="anschaun")
			m_Textfeld="\n\n\n\n\n\n\n\t\t"+m_Gegenstand;
			UpdateData(false);
		}
	}
}

void CFinalQuadDlg::Onlinks() 
{
	
	m_X--;
	m_Xt=m_X;
	UpdateData(false);
	
}

void CFinalQuadDlg::Onvor() 
{
	
	m_Y++;
	m_Yt=m_Y;
	UpdateData(false);
	
}

void CFinalQuadDlg::Onhoch() 
{
	
	m_Z++;
	m_Zt=m_Z;
	UpdateData(false);
}

void CFinalQuadDlg::Onzurueck() 
{
	
	m_Y--;
	m_Yt=m_Y;
	UpdateData(false);
}

void CFinalQuadDlg::Onrunter() 
{
	
	m_Z--;
	m_Zt=m_Z;
	UpdateData(false);
}

void CFinalQuadDlg::Onrechts() 
{
	
	m_X++;
	m_Xt=m_X;
	UpdateData(false);
}

CString CheckPlace(int m_X,int m_Y,int m_Z)
{
	CString m_Textfeld;
	if(m_X==1 && m_Y==1 && m_Z==1)
	{
		m_Textfeld="Im deinem Zimmer befindet sich nichts, was gerade von bedeutung wäre.";
	}
	else
	{
		if(m_X==2 && m_Y==1 && m_Z==1)
		{
			
			m_Textfeld="Oh, ein Hase";
		}
		else
		{
			if(m_X==2 && m_Y==2 && m_Z==1)
			{
				m_Textfeld="Oh, eine Hose";
				
			}
			else
			{
				if(m_X==2 && m_Y==2 && m_Z==2)
				{
					m_Textfeld="Viele kleine Lose";
					
				}
				else
				{
					
					m_Textfeld="Nix da";
				}
			}
		}
	}


return m_Textfeld;
}
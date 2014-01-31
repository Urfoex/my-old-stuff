////////////////////////////////////////////////////////////////////////
//********************************************************************//
//********************************************************************//
//**  _____  _____   _____              _    _____           _____  **//
//** |     |      | |     | |     |    /    |     | |     | /     \ **//
//** |     |      | |     | |     |   /     |     | |     | \     / **//
//** |_____|  ____| |       |_____|  /      |       |_____|    __/  **//
//** |  \         | |   ___ |     | /___|__ |       |     |   /     **//
//** |   \        | |     | |     |     |   |       |     |  /      **//
//** |    \       | |     | |     |     |   |     | |     | /     \ **//
//** |     \ _____| |_____| |     |     |   |_____| |     | \_____/ **//
//**                                                                **//
//** created 2004 by Manuel Bellersen Kakarott2003@yahoo.de         **//
//********************************************************************//
//********************************************************************//
////////////////////////////////////////////////////////////////////////


#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <conio.h>

void v_Komplet();

void v_Komplet()
{

}

int main()
{
	ofstream o_Reghack("R3gH4ck.reg"); //R3gH4ck.reg Datei anlegen
	char cFrage;

	int iJa=106;
	char cJa=iJa;
	char cText[300];

///////////////////////////////////
// Initialisierung von ä , ö , ü //
///////////////////////////////////
	int iUE=129;
	int iAE=132;
	int iOE=148;
	int iOOE=153;
	int iAAE=142;
	int iSZ=225;
	char OE;
	OE=iOOE;
	char sz;
	sz=iSZ;
	char ue;
	ue=iUE;
	char ae;
	ae=iAE;
	char Ae;
	Ae=iAAE;
	char oe;
	oe=iOE;

/////////////////////////////////
// R3gH4ck-Eintrag in Registry //
/////////////////////////////////
	o_Reghack << "REGEDIT4" << endl << endl;
	o_Reghack << "[HKEY_CURRENT_USER\\Software\\R3gH4ck]" << endl ;
	o_Reghack << "\"Version\"=\"1.0\"" << endl ;
	o_Reghack << "\"Hersteller\"=\"Manuel Bellersen\"" << endl ;
	o_Reghack << "\"Datum\"=\"2004\"" << endl ;
	o_Reghack << "\"eMail\"=\"Kakarott2003@yahoo.de\"" << endl << endl ;

//////////////////
// R3gH4ck-Bild //
//////////////////
	cout << "********************************************************************\n";
	cout << "********************************************************************\n";
	cout << "**  _____  _____   _____              _    _____           _____  **\n";
	cout << "** |     |      | |     | |     |    /    |     | |     | /     \\ **\n";
	cout << "** |     |      | |     | |     |   /     |     | |     | \\     / **\n";
	cout << "** |_____|  ____| |       |_____|  /      |       |_____|    __/  **\n";
	cout << "** |  \\         | |   ___ |     | /___|__ |       |     |   /     **\n";
	cout << "** |   \\        | |     | |     |     |   |       |     |  /      **\n";
	cout << "** |    \\       | |     | |     |     |   |     | |     | /     \\ **\n";
	cout << "** |     \\ _____| |_____| |     |     |   |_____| |     | \\_____/ **\n";
	cout << "**                                                                **\n";
	cout << "** created 2004 by Manuel Bellersen Kakarott2003@yahoo.de         **\n";
	cout << "********************************************************************\n";
	cout << "********************************************************************\n";
	cout << endl ;
	
	cout << "die Fragen beantworten mit\n";
	cout << "(j)a -> an | (n)ein -> aus\n\n";

//////////////////////////////////////////
// Anfang der Registry-Einträge-Abfrage //
//////////////////////////////////////////

////////////////////////////////////////////////////
// Registry EditierTools verbieten (auch regedit) //
////////////////////////////////////////////////////
	cout << "Registry EditierTools verbieten (auch regedit) : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"DisableRegistryTools\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"DisableRegistryTools\"=dword:0" << endl << endl;
	}

/////////////////////////
// Suchen im Startmenü //
/////////////////////////
	cout << "\"Suchen\" im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoFind\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoFind\"=dword:1" << endl << endl;
	}

/////////////////////////
// Ausführen im Startmenü //
/////////////////////////
	cout << "\"Ausf" << ue << "ren\" im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoRun\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoRun\"=dword:1" << endl << endl;
	}

///////////////////////////////////
// Systemsteuerung  im Startmenü //
///////////////////////////////////
	cout << "\"Systemsteuerung\" im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSetFolders\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSetFolders\"=dword:1" << endl << endl;
	}

/////////////////////////////////////////////////////////////
// Taskleisteneinstellung in Systemsteuerung  im Startmenü //
/////////////////////////////////////////////////////////////
	cout << "Taskleisteneinstellung in Systemsteuerung im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSetTaskbar\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSetTaskbar\"=dword:1" << endl << endl;
	}

////////////////////////////
// Dokumente im Startmenü //
////////////////////////////
	cout << "\"Dokumente\" im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoRecentDocsMenu\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoRecentDocsMenu\"=dword:1" << endl << endl;
	}

////////////////////////////////////////////////
// Dokumente im Startmenü bei Beenden löschen //
////////////////////////////////////////////////
	cout << "\"Dokumente\" im Startmen" << ue << " beim Beenden l" << oe << "schen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"ClearRecentDocsOnExit\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"ClearRecentDocsOnExit\"=dword:0" << endl << endl;
	}

//////////////////////////
// Beenden im Startmenü //
//////////////////////////
	cout << "\"Beenden\" im Startmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoClose\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoClose\"=dword:1" << endl << endl;
	}

///////////////////////////
// keine Systemsteuerung //
///////////////////////////
	cout << "keine Systemsteuerung : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NODispCPL\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NODispCPL\"=dword:0" << endl << endl;
	}

///////////////////////////////////
// kein "Hintergrund" in Anzeige //
///////////////////////////////////
	cout << "kein \"Hintergrund\" in Anzeige : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispBackgroundPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispBackgroundPage\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////
// kein "Bildschirmschoner" in Anzeige //
/////////////////////////////////////////
	cout << "kein \"Bildschirmschoner\" in Anzeige : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispScrsavPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispScrsavPage\"=dword:0" << endl << endl;
	}

///////////////////////////////////
// kein "Darstellung" in Anzeige //
///////////////////////////////////
	cout << "kein \"Darstellung\" in Anzeige : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispAppearancePage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispAppearancePage\"=dword:0" << endl << endl;
	}

///////////////////////////////////
// kein "Einstellung" in Anzeige //
///////////////////////////////////
	cout << "kein \"Einstellung\" in Anzeige : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispSettingsPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDispSettingsPage\"=dword:0" << endl << endl;
	}

//////////////////////////////////////////
// kein "Kennwörter" in Systemsteuerung //
//////////////////////////////////////////
	cout << "kein \"Kennw" << oe << "rter\" in Systemsteuerung : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoSecCPL\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoSecCPL\"=dword:0" << endl << endl;
	}

////////////////////////////////////////
// kein "Kennwort ändern" in Kennwörter //
////////////////////////////////////////
	cout << "kein \"Kennwort " << ae << "ndern\" in Kennw" << oe << "rter : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoPwdPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoPwdPage\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////
// keine "Benutzerprofile" in Kennwörter //
/////////////////////////////////////////
	cout << "keine \"Benutzerprofile\" in Kennw" << oe << "rter : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoAdminPaqe\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoAdminPaqe\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// kein "Benutzer" in Systemsteuerung //
//////////////////////////////////////
	cout << "kein \"Benutzer\" in Systemsteuerung : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoProfilePage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoProfilePage\"=dword:0" << endl << endl;
	}

////////////////////////////
// keine "Geräte" in System //
////////////////////////////
	cout << "keine \"Ger" << ae << "te\" in System : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDevMgrPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoDevMgrPage\"=dword:0" << endl << endl;
	}

/////////////////////////////////////
// keine Hardwareprofile in System //
/////////////////////////////////////
	cout << "keine \"Hardwareprofile\" in System : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoConfigPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoConfigPage\"=dword:0" << endl << endl;
	}

/////////////////////////////////////
// kein Dateisystem in System //
/////////////////////////////////////
	cout << "kein \"Dateisystem\" in System : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoFileSysPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoFileSysPage\"=dword:0" << endl << endl;
	}

////////////////////////////////////////
// kein virtueller Speicher in System //
////////////////////////////////////////
	cout << "kein \"virtueller Speicher\" in System : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoVirtMemPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System]" << endl;
		o_Reghack << "\"NoVirtMemPage\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////
// keine Zugriffssteuerung in Netzwerk //
/////////////////////////////////////////
	cout << "keine \"Zugriffssteuerung\" in Netzwerk : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNetSetupSecurityPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNetSetupSecurityPage\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// kein Netzwerk in Systemsteuerung //
//////////////////////////////////////
	cout << "kein \"Netzwerk\" in Systemsteuerung : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNelSetup\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNelSetup\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// keine Identifikation in Netzwerk //
//////////////////////////////////////
	cout << "kein \"Identifikation\" in Netzwerk : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNetSetupIDPage\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoNetSetupIDPage\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// keine Dateifreigabe in Netzwerk //
//////////////////////////////////////
	cout << "kein \"Dateifreingabe\" in Netzwerk : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoFileSharingControl\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoFileSharingControl\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// keine Druckerfreigabe in Netzwerk //
//////////////////////////////////////
	cout << "kein \"Druckerfreingabe\" in Netzwerk : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoPrintSharing\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Network]" << endl;
		o_Reghack << "\"NoPrintSharing\"=dword:0" << endl << endl;
	}

////////////////////////
// keine MS-Dos Prompt //
////////////////////////
	cout << "kein MS-Dos Prompt : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"Disabled\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"Disabled\"=dword:0" << endl << endl;
	}

////////////////////////
// keine MS-Dos Prompt //
////////////////////////
	cout << "kein MS-Dos Prompt : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"Disabled\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"Disabled\"=dword:0" << endl << endl;
	}

//////////////////////////////
// keine Single-Mode MS-Dos //
//////////////////////////////
	cout << "kein Single-Mode MS-Dos : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"NoRealMode\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\WinOldApp]" << endl;
		o_Reghack << "\"NoRealMode\"=dword:0" << endl << endl;
	}

////////////////////////////////////////
// Laufwerke im Arbeitsplatz anzeigen //
////////////////////////////////////////
	cout << "Laufwerke im Arbeitsplatz anzeigen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDrives\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDrives\"=dword:03ffffff" << endl << endl;
	}

////////////////////////////////////////////////
// Netzwerklaufwerke auf dem Desktop anzeigen //
////////////////////////////////////////////////
	cout << "Netzwerklaufwerke auf dem Desktop anzeigen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoNetHood\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoNetHood\"=dword:1" << endl << endl;
	}

///////////////////////////////////////
// Internet auf dem Desktop anzeigen //
///////////////////////////////////////
	cout << "Internet auf dem Desktop anzeigen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"Nolnternetlcon\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"Nolnternetlcon\"=dword:1" << endl << endl;
	}

///////////////////////////////////
// Desktop speichern und sichern //
///////////////////////////////////
	cout << "Desktop speichern und sichern (keine " << Ae << "nderungen mehr m" << oe << "glichn) : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSaveSettings\"=1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoSaveSettings\"=0" << endl << endl;
	}

///////////////////////////
// Icons auf dem Desktop //
///////////////////////////
	cout << "Icons auf dem Desktop : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDesktop\"=dword:0" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDesktop\"=dword:1" << endl << endl;
	}

///////////////////////////
// Explorer-Titel Ändern //
///////////////////////////
	cout << "Explorer-Titel " << Ae << "ndern : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		cout << "neuen Titel eingeben (kein " << ae << " " << oe << " "  << ue << " "  << sz << " ) : ";
		cin.ignore(1,'\n');
		cin.get(cText,299);
		o_Reghack << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Internet Explorer\\Main]" << endl;
		o_Reghack << "\"Window Title\"=\"" << cText << "\"" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Internet Explorer\\Main]" << endl;
		o_Reghack << "\"Window Title\"=\"\"" << endl << endl;
	}

//////////////////////////////////////
// Explorer geht nicht zu schließen //
//////////////////////////////////////
	cout << "Explorer geht nicht zu schlie" << sz << "en : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoRecentDocsMenu\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoRecentDocsMenu\"=dword:0" << endl << endl;
	}

///////////////////////////////////////
// Explorer hat kein Rechtsklickmenü //
///////////////////////////////////////
	cout << "Explorer hat kein Rechtsklickmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserContextMenu\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserContextMenu\"=dword:0" << endl << endl;
	}

///////////////////////////////////////////
// Explorer hat kein TOOL / Options Menü //
///////////////////////////////////////////
	cout << "Explorer hat kein Tool -> Optionsmen" << ue << " : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserOptions\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserOptions\"=dword:0" << endl << endl;
	}

///////////////////////////////
// Explorer hat kein Save As //
///////////////////////////////
	cout << "Explorer hat kein Save As : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserSaveAs\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoBrowserSaveAs\"=dword:0" << endl << endl;
	}

///////////////////////////////////
// Explorer hat keine Favorieten //
///////////////////////////////////
	cout << "Explorer hat keine Favorieten : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFavorites\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFavorites\"=dword:0" << endl << endl;
	}

///////////////////////////////////
// Explorer hat kein Datei "Neu" //
///////////////////////////////////
	cout << "Explorer hat kein Datei -> NEU : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFileNew\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFileNew\"=dword:0" << endl << endl;
	}

//////////////////////////////////////
// Explorer hat kein Datei "Öffnen" //
//////////////////////////////////////
	cout << "Explorer hat kein Datei ->" << OE << "ffnen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFileOpen\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFileOpen\"=dword:0" << endl << endl;
	}

//////////////////////////////
// Explorer hat kein Finden //
//////////////////////////////
	cout << "Explorer hat kein Finden : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFindFiles\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoFindFiles\"=dword:0" << endl << endl;
	}

//////////////////////////////////////////////
// Explorer hat kein Downloadziel auswählen //
//////////////////////////////////////////////
	cout << "Explorer hat kein Downloadziel ausw" << ae << "hlen : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoSelectDownloadDir\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoSelectDownloadDir\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////
// Explorer hat keine FullScreen Optin //
/////////////////////////////////////////
	cout << "Explorer hat keine FullScreen Option : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoTheaterMode\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions]" << endl;
		o_Reghack << "\"NoTheaterMode\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////////////////
// Vorhandene Drucker können nicht gelöscht werden //
/////////////////////////////////////////////////////
	cout << "vorhandene Drucker k" << oe << "nnen nicht gel" << oe << "scht werden : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDeletePrinter\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoDeletePrinter\"=dword:0" << endl << endl;
	}

/////////////////////////////////////////////
// Drucker können nicht hinzugefügt werden //
/////////////////////////////////////////////
	cout << "Drucker k" << oe << "nnen nicht hinzugef" << ue << "gt werden : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoAddPrinter\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer]" << endl;
		o_Reghack << "\"NoAddPrinter\"=dword:0" << endl << endl;
	}

////////////////////////////
// CD-Autorun unterbinden //
////////////////////////////
	cout << "CD-Autorun unterbinden : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\CDRom]" << endl;
		o_Reghack << "\"Autorun\"=dword:1" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\CDRom]" << endl;
		o_Reghack << "\"Autorun\"=dword:1" << endl << endl;
	}

//////////////////////
// BEEP bei Fehlern //
//////////////////////
	cout << "BEEP bei Fehlern : ";
	cin >> cFrage;
	
	if (cFrage==cJa)
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Control Panel\\Sound]" << endl;
		o_Reghack << "\"Beep\"=\"yes\"" << endl << endl;
	}
	else
	{
		o_Reghack << "[HKEY_CURRENT_USER\\Control Panel\\Sound]" << endl;
		o_Reghack << "\"Beep\"=\"no\"" << endl << endl;
	}

	o_Reghack.close();

	cout << "\n\nNun f" << ue << "hren sie bitte die R3gH4ck.reg aus und stimmen sie zu !\n";
	cout << "Anschlie" << sz << "end m" << ue << "ssen sie Neustarten , damit sich alles " << ae << "ndert .\n";
	cout << "OK ? [ (j)a / (n)ein ] ";
	cin >> cFrage;
	return 0;
}
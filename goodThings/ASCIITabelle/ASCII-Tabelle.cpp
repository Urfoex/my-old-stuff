/////////////////////////////////////////////////////////////
//    ASCII-Tabelle , sowie Umrechnung Zahl in Zeichen     //
//  erstellt von Manuel Bellersen (Kakarott2003@yahoo.de)  //
/////////////////////////////////////////////////////////////


//Einbinden von wichtigen Dateien
#include <iostream.h>
#include "Sonderzeichen.h"

//Deklaration der Funktionen
short int auswahlnummer(int auswahl);
short int main();

//Definition der Buchstaben ä ö ü
int alf=129,ralf=132,malf=148,salf=154;

//Definition was gemacht werden soll bei Eingabe einer Menünummer
short int auswahlnummer(int auswahl)
{
	unsigned short int uzo;
	Sonderzeichen sonderzwei;
	int zahl;
	int u;
	char ue;
		ue=alf;
	char ae;
		ae=ralf;
	char oe;
		oe=malf;
	char Ue;
		Ue=salf;

	if (auswahl==1)
	{
		u=1;
		uzo=7;
	}

	if (auswahl==2)
	{
		u=11;
		uzo=100;
	}
	
	if (auswahl==3)
	{
		u=100;
		uzo=255;
	}

	if (auswahl==4)
	{
		u=0;
		uzo=0;
		cout << "\n7 f" << ue << "r nichts\n8 f" << ue << "r ein Feld zur" << ue << "ck\n";
		cout << "9 f" << ue << "r ein TAB vorw" << ae << "rts\n10 f" << ue << "r n" << ae << "chste Zeile\n";
		cout << "13 f" << ue << "r bis Anfang l" << oe << "schen bzw Enter\n26 f" << ue << "r bis Ende l" << oe << "schen\n";
		cout << "32 , 255 f" << ue << "r jeweils ein Feld vor\n";
	}


	if (auswahl==5)
	{
		u=0;
		uzo=0;
		cout << "\nBitte geben sie ihre Zahl ein \n( das Zeichen steht dann zwischen zwei Pfeilen \nsollte dies nicht der Fall sein , schauen sie bitte bei den Sonderzeichen rein )-: ";
		cin >> zahl;
		sonderzwei.Position(zahl);
		sonderzwei.Zeichen();
		cout <<"\n";
	}


	if (auswahl==6)
	{
		u=0;
		uzo=0;
		cout << "\nDiese Funktion steht erst in der n" << ae << "chsten Version zur verf" << ue << "gung ...\n";
	}

	if (auswahl==7)
	{
		u=0;
		uzo=0;
		cout << "\nDiese Funktion steht leider noch nicht zur verf" << ue << "gung ...\n";
	}

	if (auswahl==8)
	{
		u=0;
		uzo=0;
		cout << "\n09.03.2004 - Idee zu diesem Programm und erste Umsetzung\n";
		cout << "10.03.2004 - " << Ue << "berarbeitung : Fehlerbeseitigung\n";
		cout << "11.03.2004 - Programm enth" << ae << "lt nun weitere Funktionen ,\n";
		cout << "             sowie diese Informationen\n";
		
//Hier weitere Neuerungen und Änderungen eintregen !
		
		cout << "\nHersteller : Manuel Bellersen (Kakarott2003@yahoo.de)\n";
	}


	if (auswahl==9)
		return auswahl;
	
	while(u<uzo)
	{	
		if (auswahl==1)
		{
			char zeichenn=u;
			cout << "  " << zeichenn << " " << u;		
			u++;
		}

		if (auswahl==2)
		{
			if (u==13)
				u++;

			if (u==26)
				u++;
		
			if (u==32)
				u++;
			
			char zeichenn=u;
			cout << "    " << zeichenn << " " << u;		
			u++;
		}
	
		if (auswahl==3)
		{
			char zeichenn=u;
			cout << "   " << zeichenn << " " << u;		
			u++;
		}
	}

	cout << endl;
	return auswahl;
}

//Start des Hauptprogramms
short int main()
{
	unsigned short int u,number,noch;
	char ue;
	ue=alf;

	cout << "Programm zur Anzeige von DOS - ASCII - Zeichentabelle\n";
	cout << "-----------------------------------------------------\n";
	cout << "In welchem Bereich soll die Liste angezeigt werden ?\n\n";
	cout << "1 f" << ue << "r 1 bis 6 \n2 f" << ue << "r 11 bis 99 \n3 f" << ue << "r 100 bis 254\n";
	cout << "4 f" << ue << "r Sonderzahlen \n5 f" << ue << "r Umrechnung : Zahl -> Zeichen \n";
	cout << "6 f" << ue << "r Umrechnung : Zeichen -> Zahl \n7 f" << ue << "r Hilfe \n";
	cout << "8 f" << ue << "r Information \n9 f" << ue << "r Exit \n\n";
	
	cin >> number;
	u=auswahlnummer(number);

	if (u==9)
		return 0;

	cout << endl;	
	cout << "\nNochmal ? (1 f" << ue << "r ja | 2 f" << ue << "r Exit)   ->  ";
	cin >> noch;

	if (noch==1)
	{
		cout << endl;
		main();
	}

	else
		return 0;
	return 0;
}
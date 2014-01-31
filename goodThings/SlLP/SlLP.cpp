///////////////////////////////////////////////////////////////////////////
//                  SlLP - Server like Login Prgogramm                   //
// by Kakarott2003@yahoo.de || ICQ: 169472746 || Kakarott2003@jabber.org //
///////////////////////////////////////////////////////////////////////////
#include <iostream.h>

int i_Port(char);
void v_Check(int iPort, char cUser[], char cPass[]);
bool b_SlLP(char cUser[], char cPass[], char cCUser[], char cCPass[], int iUserPort, int iPassPort);

int main (int argc, char *argv[])
{
	char cPort[]="-port";
	char cUser[]="-user";
	char cPass[]="-pass";

	char cHilfe[]="\n***********************************\n*       Willkommen bei SlLP,      *\n* dem Server-like-Login-Prgogramm *\n***********************************\n* Programmierer: Manuel Bellersen *\n* eMail:Kakarott2003@yahoo.de     *\n* ICQ: 169472746                  *\n***********************************\n\nsllp -port [x] -user [x] -pass [x] \n\n***********************************\n* Level 0: \"test\"-Level           *\n***********************************\n*           Viel Spass!           *\n***********************************\n";

    int iZaehler=0;
	int iCounter=0;
	int iPort=0;

	if(argc==7)
	{
		//////////////
		// -port ?? //
		//////////////
		for(iZaehler=0;iZaehler<6;iZaehler++)
		{
			if(argv[1][iZaehler]==cPort[iZaehler])
					iCounter++;
			else
				iCounter--;
		}
		if(iCounter!=6)
			cout << "\"-port\"-Schreibweise ueberpruefen\n";
		else
		{
			/////////////////////
			// Welcher Port ?? //
			/////////////////////
			iCounter=0;
			iCounter=i_Port(argv[2][0]);
			if(iCounter<0)
				return 0;
			if(argv[2][1]) // einstelliger Port
			{
				if(argv[2][2]) // dreistelliger Port -> Error
				{
					cout << "es gibt nicht so viele Ports\n";
					return 0;
				}
				iCounter=iCounter*10;
				iCounter=iCounter+i_Port(argv[2][1]);
			}
			if(iCounter<0)
			{
				return 0;
			}
			else
			{
				iPort=iCounter;
				//////////////
				// -user ?? //
				//////////////
				iCounter=0;
				for(iZaehler=0;iZaehler<6;iZaehler++)
				{
					if(argv[3][iZaehler]==cUser[iZaehler])
						iCounter++;
					else
						iCounter--;
				}
				if(iCounter!=6)
					cout << "\"-user\"-Schreibweise ueberpruefen\n";
				else
				{
					//////////////
					// -pass ?? //
					//////////////
					iCounter=0;
					for(iZaehler=0;iZaehler<6;iZaehler++)
					{
						if(argv[5][iZaehler]==cPass[iZaehler])
							iCounter++;
						else
							iCounter--;
					}
					if(iCounter!=6)
						cout << "\"-pass\"-Schreibweise ueberpruefen\n";
					else
					{
						v_Check(iPort,argv[4],argv[6]);
					}
				}
			}
		}
	}
	else
		cout << cHilfe;
	return 0;
}

////////////////
// Funktionen //
////////////////

////////////////////
// Port festlegen //
////////////////////
int i_Port(char cPort)
{
	int iCounter=0;
	switch(cPort)
	{
	case 32:	break;
	case 48:	iCounter=0;
				break;
	case 49:	iCounter++;
				break;
	case 50:	iCounter=iCounter+2;
				break;
	case 51:	iCounter=iCounter+3;
				break;
	case 52:	iCounter=iCounter+4;
				break;
	case 53:	iCounter=iCounter+5;
				break;
	case 54:	iCounter=iCounter+6;
				break;
	case 55:	iCounter=iCounter+7;
				break;
	case 56:	iCounter=iCounter+8;
				break;
	case 57:	iCounter=iCounter+9;
				break;
	default:	cout << "Error im Portstelle 1 oder 2.\n";
				iCounter=-100;
				break;
	}
	return iCounter;
}

///////////////////////////
// Port+User+Pass ?=? ok //
///////////////////////////
void v_Check(int iPort,char cUser[],char cPass[])
{
	int iCounter=0;
	int iZaehler=0;

	int iUser[5];
	int iPass[5];
	
	///////////////////
	// Benutzernamen //
	///////////////////
	char cCUser[6][22]={{"test"},
						{"User"},
						{"Manuel"},
						{"eMail"},
						{"Kakarott2003@yahoo.de"},
						{"ja"}};
	iUser[0]=5;
	iUser[1]=5;
	iUser[2]=7;
	iUser[3]=6;
	iUser[4]=22;
	iUser[5]=3;

	////////////////
	// Passwörter //
	////////////////
	char cCPass[6][10]={{"test"},
						{"Pass"},
						{"Bellersen"},
						{"ICQ"},
						{"169472746"},
						{"nein"}};
	iPass[0]=5;
	iPass[1]=5;
	iPass[2]=10;
	iPass[3]=4;
	iPass[4]=10;
	iPass[5]=5;

	switch(iPort)
	{
	////////////////////////
	// Port 0: test--test //
	////////////////////////
	case 0:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Wie heissen die letzten beiden Angaben?\n";
				break;
	////////////////////////
	// Port 1: User--Pass //
	////////////////////////
	case 1:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Wie heisst der Programmierer von SlLP?\n";
				break;
	///////////////////////////////
	// Port 2: Manuel--Bellersen //
	///////////////////////////////
	case 2:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Wie kann man ihn erreichen(Methoden)?\n";
				break;
	////////////////////////
	// Port 3: eMail--ICQ //
	////////////////////////
	case 3:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Wie kann man ihn erreichen(Angaben)?\n";
				break;
	//////////////////////////////////////////////
	// Port 4: Kakarott2003@yahoo.de--169472746 //
	//////////////////////////////////////////////
	case 4:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Welches sind die bedeutensten Antworten?\n";
				break;
	//////////////////////
	// Port 5: ja--nein //
	//////////////////////
	case 5:		if(b_SlLP(cUser,cPass,cCUser[iPort],cCPass[iPort],iUser[iPort],iPass[iPort]))
					cout << "\nLevel " << iPort << " geschafft\nLevel " << iPort+1 << ": Sie haben das Demoende erreicht. Glueckwunsch.\n";
				break;
	//////////////////
	// Default-Port //
	//////////////////
	default:cout << "Nutze die richtigen Ports.\n";
			break;	
	}
	cout << "\nPort: " << iPort << endl;
	cout << "User: " << cUser << endl;
	cout << "Pass: " << cPass << "\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Usereingabe, Passeingabe, Vorgabeuser, Vorgabepass, Userstellen, Passstellen -- Checker //
/////////////////////////////////////////////////////////////////////////////////////////////
bool b_SlLP(char cUser[], char cPass[], char cCUser[], char cCPass[], int iUserPort, int iPassPort)
{
	int iCounter=0;
	int iZaehler=0;

	for(iZaehler=0;iZaehler<iUserPort;iZaehler++)
	{
		if(cUser[iZaehler]==cCUser[iZaehler])
			iCounter++;
		else
			iCounter--;
	}
		if(iCounter!=iUserPort)
			cout << "User falsch\n";
		else
		{
			iCounter=0;
			for(iZaehler=0;iZaehler<iPassPort;iZaehler++)
			{
				if(cPass[iZaehler]==cCPass[iZaehler])
					iCounter++;
				else
					iCounter--;
			}
			if(iCounter!=iPassPort)
				cout << "Pass falsch\n";
			else
			{
				return true;
			}
		}
	return false;
}
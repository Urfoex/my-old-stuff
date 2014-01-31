/*      ********************************\n
		** Willkommen zu 'WoodStockS' **\n
		********************************\n
		**  Bei diesem Spiel muessen  **\n
		** sie nur Hoelzchen ziehen.  **\n
		**   Wer das letzte hat, hat  **\n
		** ´        verloren.         **\n
		**      Viel Spass dabei !    **\n
		********************************\n
		** Erstellt von Manuel Bellersen\n
		** Mail: Kakarott2003@yahoo.de**\n
		********************************\n
*/

#include <iostream.h>

bool b_A();
bool b_MC();
void v_GMC(bool);

int main()
{
	bool bA=false;
	cout << "********************************\n** Willkommen zu \'WoodStockS\' **\n********************************\n**  Bei diesem Spiel muessen  **\n** sie nur Hoelzchen ziehen.  **\n**   Wer das letzte hat, hat  **\n** ´        verloren.         **\n**      Viel Spass dabei !    **\n********************************\n** Erstellt von Manuel Bellersen\n** Mail: Kakarott2003@yahoo.de**\n********************************\n\n";
	while(bA==false)
	{
		v_GMC(b_MC());
		bA=b_A();
	}
	return 0;
}

///////////////
// Nochmal?? //
///////////////
bool b_A()
{
	char cA;
	cout << "\nNoch ein Spiel? (0-ja|1-nein): ";
	cin >> cA;
	if(cA==48)
		return false;	//0
	else
	{
		cout << "\nAuf Wiedersehn\n";
		return true;	//1
	}
}

////////////////
// Anfänger?? //
////////////////
bool b_MC()
{
	char cMC;
	cout << "\nWer darf anfangen? ((M)ensch/(C)omputer): ";
	cin >> cMC;
	if(cMC==77)
		return false;	//Mensch
	else
		return true;	//Computer
}

//////////
// Game //
//////////
void v_GMC(bool bMC)
{
	int iHolz=12;
	int iZ;
	while(iHolz!=0)
	{	
		cout << "Es gibt noch " << iHolz << " Hoelzchen.\n";
		if(bMC==false)
		{
			cout << "\nWieviel ziehen sie? (1/2/3): ";
			cin >> iZ;
			if(iZ<1)
				iZ=1;
			if(iZ>3)
				iZ=3;
			iHolz=iHolz-iZ;
			if(iHolz<0)
				iHolz=0;
			else
			{
				cout << "Sie nehmen " << iZ << " Hoelzchen.\n";
				cout << "Es bleiben noch " << iHolz << " Hoelzchen uebrig.\n";
			}
		}
		switch(iHolz)
		{
		case 12:	iHolz=iHolz-1;
					cout << "Computer zieht 1\n";
					break;
		case 11:	iHolz=iHolz-3;
					cout << "Computer zieht 3\n";
					break;
		case 10:	iHolz=iHolz-2;
					cout << "Computer zieht 2\n";
					break;
		case 9:		iHolz=iHolz-1;
					cout << "Computer zieht 1\n";
					break;
		case 8:		iHolz=iHolz-3;
					cout << "Computer zieht 3\n";
					break;
		case 7:		iHolz=iHolz-2;
					cout << "Computer zieht 2\n";
					break;
		case 6:		iHolz=iHolz-1;
					cout << "Computer zieht 1\n";
					break;
		case 5:		iHolz=iHolz-1;
					cout << "Computer zieht 1\n";
					break;
		case 4:		iHolz=iHolz-3;
					cout << "Computer zieht 3\n";
					break;
		case 3:		iHolz=iHolz-2;
					cout << "Computer zieht 2\n";
					break;
		case 2:		iHolz=iHolz-1;
					cout << "Computer zieht 1\n";
					break;
		case 1:		iHolz=iHolz-1;
					cout << "Computer nimmt das letzte Hoelzchen und verliert.\n";
					break;
		case 0:		cout << "Sie haben das letzte Hoelzchen genommen und verlieren somit.\n";
					break;
		default:	cout << "Irgendwas stimmt mit ihren Hoelzchen nicht.\n";
					iHolz=0;
					break;
		}
		bMC=false;
	}
}
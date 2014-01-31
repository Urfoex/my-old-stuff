#include <iostream.h>
#include <string.h>

class c_Objekt
{
public:
	
	/*eFdurchsichtig-0, eFweiss-1, eFgrau-2, eFgelb-3, eForange-4,eFrot-5, eFlila-6, eFblau-7, eFgruen-8, eFbraun-9, eFschwarz-10*/

	float fDichte;
	float fMasse;		// kg
	float fTemperatur;	// K
	float fVolumen;		// m^3
	
	unsigned short usLadung;	//
	unsigned short usFarbe;		//
	unsigned short usZustand;	//

	double dEnergie;	// J

	void v_Check();

private:

	enum eFarbe { eFdurchsichtig, eFweiss, eFgrau, eFgelb, eForange, eFrot, eFlila, eFblau, eFgruen, eFbraun, eFschwarz};
	enum eLadung { eLneutral, eLnegativ, eLpositiv};
	enum eZustand { eZfest, eZfluessig, eZgasfoermig};
	
	char cFarbe[12];

};


int main()
{
	enum eFarbe { eFdurchsichtig, eFweiss, eFgrau, eFgelb, eForange, eFrot, eFlila, eFblau, eFgruen, eFbraun, eFschwarz};
	enum eLadung { eLneutral, eLnegativ, eLpositiv};
	enum eZustand { eZfest, eZfluessig, eZgasfoermig};
	c_Objekt cOWasserWarm;

	cOWasserWarm.fMasse=10;
	cOWasserWarm.fTemperatur=273;
	cOWasserWarm.fVolumen=0.1;
	cOWasserWarm.dEnergie=1000;
	cOWasserWarm.usLadung=65535;
	cOWasserWarm.usZustand=-65535;
	cOWasserWarm.usFarbe=eFdurchsichtig;

	cOWasserWarm.v_Check();

	return 0;
}

void c_Objekt::v_Check()
{
	strcpy(cFarbe,"durchsichtig");
	
	if(usFarbe<eFweiss || usFarbe>eFschwarz) usFarbe=eFdurchsichtig;

	for(int ia=eFdurchsichtig;usFarbe!=ia;ia++)
	{
		switch(ia)
		{

		case 0:	strcpy(cFarbe,"weiss       ");
				break;
		case 1:	strcpy(cFarbe,"grau");
				break;
		case 2:	strcpy(cFarbe,"gelb");
				break;
		case 3:	strcpy(cFarbe,"orange");
				break;
		case 4:	strcpy(cFarbe,"rot   ");
				break;
		case 5:	strcpy(cFarbe,"lila");
				break;
		case 6:	strcpy(cFarbe,"blau");
				break;
		case 7:	strcpy(cFarbe,"gruen");
				break;
		case 8:	strcpy(cFarbe,"braun");
				break;
		case 9:	strcpy(cFarbe,"schwarz");
				break;
		default:strcpy(cFarbe,"durchsichtig");
				break;
		}
	}

	cout << "Farbe:  ";
	for(int ib=0;ib<12;ib++)
	{
		cout << cFarbe[ib] ;
	}

	cout << endl;
	cout << "Platz:         " << usFarbe << endl;
	cout << "Masse(kg):     " << fMasse << endl;
	cout << "Temperatur(K): " << fTemperatur << endl;
	cout << "Volumen(m^3):  " << fVolumen << endl;
	cout << "Energie(J):    " << dEnergie << endl ;
	cout << "Ladung:        " << usLadung << endl;
	cout << "Zustand:       " << usZustand << endl;
	cout << endl;
}
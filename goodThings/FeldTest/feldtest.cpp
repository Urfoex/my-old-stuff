#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <time.h>

#define Breite 36
#define Laenge 12
#define sichtbareBreite 38
#define sichtbareLaenge 14

using namespace std;

void SpielfeldSauber(char sichtbaresSpielfeld[sichtbareBreite][sichtbareLaenge]);
void bekommeSpielfeld(char sichtbaresSpielfeld[sichtbareBreite][sichtbareLaenge], const char Spielfeld[Breite][Laenge], unsigned short int BereichX, unsigned short int BereichY);
void Level1(char Spielfeld[Breite][Laenge]);
void nutzenBett(char &Bett);
void nutzenSchrank(char &Schrank);
void nutzenFenster();
void nutzenTisch(char &Tisch);
void nutzenPC(char &PC);
void nutzenBuecher();
void nutzenTuer(char &Tuer,bool &Ende);
void nutzenWand(char &Wand, bool &Ende);
void nutzenStuhl();
void ansehnBett(const char &Bett);
void ansehnSchrank();
void ansehnFenster();
void ansehnTisch(const char &Tisch);
void ansehnPC(const char &PC);
void ansehnBuecher();
void ansehnTuer(const char &Tuer);
void ansehnWand(const char &Wand);
void ansehnStuhl();

int main(int argc, char *argv[])
{
	char Spielfeld[Breite][Laenge];
	char sichtbaresSpielfeld[sichtbareBreite][sichtbareLaenge];
	char Eingabe, Richtung, Gegenstaende[5];

	unsigned short int X=0, Y=0;
	unsigned short int BereichX=0, BereichY=0;
	bool Ende=0;

	SpielfeldSauber(sichtbaresSpielfeld);

	for(unsigned short int I=0;I<Laenge;I++)
	{	for(unsigned short int J=0;J<Breite;J++)
		{	Spielfeld[J][I]=' ' ;	}	}

	for(unsigned short int J=0;J<9;J++)
	{	Gegenstaende[J]='a' ;	}

	Level1(Spielfeld);

	X=7;	//Startposi
	Y=7;	//Startposi
	cout << "Sie erwachen und stehen auf.\n";
	Richtung='^';

	while(!Ende)
	{
		Spielfeld[X][Y]=Richtung;
		bekommeSpielfeld(sichtbaresSpielfeld,Spielfeld,BereichX,BereichY);

		for(unsigned short int I=0;I<sichtbareLaenge;I++)
		{
			for(unsigned short int J=0;J<sichtbareBreite;J++)
			{	cout << sichtbaresSpielfeld[J][I] ;	}
			cout << endl;
		}

		cout << "Sie befinden sich: X: " << X << " Y: " << Y << endl;

		cout << "Was wollen sie machen? (d)rehen, (b)ewegen, (a)nschaun, (n)utzen, (e)nde: ";
		cin >> Eingabe;

		switch(Eingabe)
		{
			case 'd': cout << "Wohin wollen sie sich drehen? (l)inks, (r)echts, (o)ben, (u)nten: ";
						cin >> Eingabe;
						switch(Eingabe)
						{
							case 'l': Richtung='<'; break;	
							case 'r': Richtung='>'; break;
							case 'o': Richtung='^'; break;
							case 'u': Richtung='v'; break;
							default: break;
						}	break;
			case 'b': switch(Richtung)
						{
							case '<': if(Spielfeld[X-1][Y]==' ')
										{Spielfeld[X][Y]=' '; X--;}
										else
											cout << "Hier geht es nicht weiter.\n";	break;
							case '>': if(Spielfeld[X+1][Y]==' ')
										{Spielfeld[X][Y]=' '; X++;}
										else
											cout << "Hier geht es nicht weiter.\n";	break;
							case '^': if(Spielfeld[X][Y-1]==' ')
										{Spielfeld[X][Y]=' '; Y--;}
										else
											cout << "Hier geht es nicht weiter.\n";	break;
							case 'v': if(Spielfeld[X][Y+1]==' ')
										{Spielfeld[X][Y]=' '; Y++;}
										else
											cout << "Hier geht es nicht weiter.\n";	break;
							default: break;
						}break;
			case 'a': switch(Richtung)
						{
							case '>': if((X==32) && (Y>3 && Y<11))
										ansehnFenster(); break;					//Fenster
							case '<': if((X==1) && (Y>0 && Y<8))
										ansehnWand(Gegenstaende[0]);	break;					//Wand
							case 'v': if((X>0 && X<20) && (Y==7))
										ansehnBett(Gegenstaende[1]);							//Bett
									  if((X>21 && X<30) && (Y==10))
										ansehnSchrank();							//Schrank
									  if((X>24 && X<30) && (Y==5))
										ansehnStuhl(); break;					//Stuhl
							case '^': if((X>0 && X<11) && (Y==1))
										ansehnTuer(Gegenstaende[2]);							//Tuer
									  if((X>11 && X<19) && (Y==3))
										ansehnBuecher();							//Buecher
									  if((X>20 && X<22) && (Y==4))
										ansehnPC(Gegenstaende[3]);								//PC
									  if((X>23 && X<30) && (Y==4))
										ansehnTisch(Gegenstaende[4]); break;					//Tisch
							default: break;
						}break;
			case 'n': switch(Richtung)
						{
							case '>': if((X==32) && (Y>3 && Y<11))
										nutzenFenster(); break;					//Fenster
							case '<': if((X==1) && (Y>0 && Y<8))
										nutzenWand(Gegenstaende[0],Ende);	break;					//Wand
							case 'v': if((X>0 && X<20) && (Y==7))
										nutzenBett(Gegenstaende[1]);							//Bett
									  if((X>21 && X<30) && (Y==10))
										nutzenSchrank(Gegenstaende[2]);							//Schrank
									  if((X>24 && X<30) && (Y==5))
										nutzenStuhl(); break;					//Stuhl
							case '^': if((X>0 && X<11) && (Y==1))
										nutzenTuer(Gegenstaende[2],Ende);							//Tuer
									  if((X>11 && X<19) && (Y==3))
										nutzenBuecher();							//Buecher
									  if((X>20 && X<22) && (Y==4))
										nutzenPC(Gegenstaende[3]);								//PC
									  if((X>23 && X<30) && (Y==4))
										nutzenTisch(Gegenstaende[4]); break;					//Tisch
							default: break;
						}break;
			case 'e': Ende=1; break;
			default: break;
		}
	}
	return EXIT_SUCCESS;
}

void SpielfeldSauber(char sichtbaresSpielfeld[sichtbareBreite][sichtbareLaenge])
{
	for(unsigned short int I=0;I<sichtbareBreite;I++)
	{	sichtbaresSpielfeld[I][0]='-';	}
	for(unsigned short int I=0;I<sichtbareBreite;I++)
	{	sichtbaresSpielfeld[I][sichtbareLaenge-1]='-';	}
	for(unsigned short int I=0;I<sichtbareLaenge;I++)
	{	sichtbaresSpielfeld[0][I]='|';	}
	for(unsigned short int I=0;I<sichtbareLaenge;I++)
	{	sichtbaresSpielfeld[sichtbareBreite-1][I]='|';	}

	for(unsigned short int I=1;I<(sichtbareBreite-1);I++)
	{	for(unsigned short int J=1;J<(sichtbareLaenge-1);J++)
		{	sichtbaresSpielfeld[I][J]=' ' ;	}	}
}

void bekommeSpielfeld(char sichtbaresSpielfeld[sichtbareBreite][sichtbareLaenge], const char Spielfeld[Breite][Laenge], unsigned short int BereichX, unsigned short int BereichY)
{
	for(unsigned short int I=1;I<(sichtbareLaenge-1);I++)
	{
		for(unsigned short int J=1;J<(sichtbareBreite-1);J++)
		{
			sichtbaresSpielfeld[J][I]= Spielfeld[(J-1)+(BereichX*sichtbareBreite)][(I-1)+(BereichY*sichtbareLaenge)];
		}
	}
}

void Level1(char Spielfeld[Breite][Laenge])
{
	Spielfeld[0][0]='/';
	Spielfeld[1][0]='_';
	Spielfeld[2][0]='T';
	Spielfeld[3][0]='_';
	Spielfeld[4][0]='U';
	Spielfeld[5][0]='_';
	Spielfeld[6][0]='E';
	Spielfeld[7][0]='_';
	Spielfeld[8][0]='R';
	Spielfeld[9][0]='_';
	Spielfeld[10][0]='_';
	Spielfeld[11][0]='\\';
	Spielfeld[11][1]='|';
	Spielfeld[11][2]='|';
	Spielfeld[12][2]='B';
	Spielfeld[13][2]='U';
	Spielfeld[14][2]='E';
	Spielfeld[15][2]='C';
	Spielfeld[16][2]='H';
	Spielfeld[17][2]='E';
	Spielfeld[18][2]='R';
	Spielfeld[19][2]='|';
	Spielfeld[20][2]='|';
	Spielfeld[21][2]='P';
	Spielfeld[22][2]='|';
	Spielfeld[23][2]='|';
	Spielfeld[25][2]='T';
	Spielfeld[26][2]='I';
	Spielfeld[27][2]='S';
	Spielfeld[28][2]='C';
	Spielfeld[29][2]='H';
	Spielfeld[30][2]='|';
	Spielfeld[31][2]='|';
	Spielfeld[20][3]='|';
	Spielfeld[21][3]='C';
	Spielfeld[22][3]='|';
	Spielfeld[23][3]='|';
	Spielfeld[24][3]='_';
	Spielfeld[25][3]='_';
	Spielfeld[26][3]='_';
	Spielfeld[27][3]='_';
	Spielfeld[28][3]='_';
	Spielfeld[29][3]='_';
	Spielfeld[30][3]='|';
	Spielfeld[31][3]='|';
	Spielfeld[32][3]='_';
	Spielfeld[33][4]='|';
	Spielfeld[33][5]='|';
	Spielfeld[33][6]='|';
	Spielfeld[33][7]='|';
	Spielfeld[33][8]='|';
	Spielfeld[33][9]='|';
	Spielfeld[33][10]='|';
	Spielfeld[34][4]='F';
	Spielfeld[34][5]='E';
	Spielfeld[34][6]='N';
	Spielfeld[34][7]='S';
	Spielfeld[34][8]='T';
	Spielfeld[34][9]='E';
	Spielfeld[34][10]='R';
	Spielfeld[35][4]='|';
	Spielfeld[35][5]='|';
	Spielfeld[35][6]='|';
	Spielfeld[35][7]='|';
	Spielfeld[35][8]='|';
	Spielfeld[35][9]='|';
	Spielfeld[35][10]='|';
	Spielfeld[32][10]='_';
	Spielfeld[9][9]='B';
	Spielfeld[10][9]='E';
	Spielfeld[11][9]='T';
	Spielfeld[12][9]='T';
	Spielfeld[20][8]='|';
	Spielfeld[20][9]='|';
	Spielfeld[20][10]='|';
	Spielfeld[20][11]='|';
	Spielfeld[21][11]='|';
	Spielfeld[22][11]='S';
	Spielfeld[23][11]='C';
	Spielfeld[24][11]='H';
	Spielfeld[25][11]='R';
	Spielfeld[26][11]='A';
	Spielfeld[27][11]='N';
	Spielfeld[28][11]='K';
	Spielfeld[29][11]='_';
	Spielfeld[30][11]='|';
	Spielfeld[31][11]='|';
	Spielfeld[23][6]='|';
	Spielfeld[24][6]='|';
	Spielfeld[30][6]='|';
	Spielfeld[31][6]='|';
	Spielfeld[23][7]='|';
	Spielfeld[24][7]='|';
	Spielfeld[25][7]='S';
	Spielfeld[26][7]='T';
	Spielfeld[27][7]='U';
	Spielfeld[28][7]='H';
	Spielfeld[29][7]='L';
	Spielfeld[30][7]='|';
	Spielfeld[31][7]='|';
	Spielfeld[23][8]='|';
	Spielfeld[31][8]='|';

	for(unsigned short int I=1;I<12;I++)
	{Spielfeld[0][I]='|';}

	for(unsigned short int I=12;I<32;I++)
	{Spielfeld[I][1]='_';}

	for(unsigned short int I=1;I<20;I++)
	{Spielfeld[I][8]='T';}
	for(unsigned short int I=1;I<8;I++)
	{Spielfeld[I][9]='|';}
	for(unsigned short int I=14;I<20;I++)
	{Spielfeld[I][9]='|';}
	for(unsigned short int I=1;I<20;I++)
	{Spielfeld[I][10]='|';}
	for(unsigned short int I=1;I<20;I++)
	{Spielfeld[I][11]='L';}
	for(unsigned short int I=25;I<30;I++)
	{Spielfeld[I][6]='-';}
	for(unsigned short int I=24;I<31;I++)
	{Spielfeld[I][8]='#';}

}


void nutzenBett(char &Bett)
{
	switch(Bett)
	{
		case 'a': cout << "Du machst das Bett.\n";
					Bett++; break;
		case 'b': cout << "Du durchwuehlst das Bett.\n";
					Bett++; break;
		case 'c': cout << "Du machst das Bett erneut.\n";
					Bett--; break;
		default: ;
	}
}

void nutzenSchrank(char &Schrank)
{
	if(Schrank=='a')
	{cout << "Du ergreifst einen Schluessel.\n"; Schrank++;}
	else
	{cout << "Die Dinge interessieren dich nicht.\n";}
}

void nutzenFenster()
{	cout << "Du kannst nichts mit dem Fenster machen. Es laesst sich auch nicht oeffnen.\n"; }

void nutzenTisch(char &Tisch)
{
	if(Tisch=='a')
	{cout << "Du raeumst den Tisch auf.\n"; Tisch++;}
	else
	{cout << "Du bringst alles auf dem Tisch durcheinander.\n"; Tisch--;}
}

void nutzenPC(char &PC)
{
	if(PC=='a')
	{	cout << "Der PC geht an.\n"; PC++;}
	else
	{	cout << "Der PC geht aus.\n";PC--;}
}

void nutzenBuecher()
{	cout << "Du schaust dir wahllos einige Buecher an.\n";}

void nutzenTuer(char &Tuer,bool &Ende)
{
	if(Tuer=='a')
	{cout << "Du ruettelst an der Tuer. Sie geht nicht auf.\n";}
	else
	{cout << "Du schliesst die Tuer auf und gehst hindurch.\nDu has das Spiel gewonnen.\nHerzlichen Gluekwunsch.\n"; Ende++;}
}

void nutzenWand(char &Wand, bool &Ende)
{
	switch(Wand)
	{
		case 'a': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'b': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'c': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'd': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'e': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'f': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'g': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'h': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'i': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n"; Wand++; break;
		case 'j': cout << "Du schlaegst verzweifelt mit dem Kopf gegen die Wand.\n";
					cout << "Dein Koerper faellt regungslos zu Boden.\n";
					cout << "Du bist gestorben.\n";
					cout << "Spiel zu Ende...\n";Ende++; break;
		default: break;
	}
}

void nutzenStuhl()
{cout << "Du setzt dich auf den Stuhl, springts jedoch wieder hoch, weil du jede Metallfeder spuehrst.\n";}

void ansehnBett(const char &Bett)
{
	switch(Bett)
	{
		case 'a': cout << "Das Bett ist noch so, wie du es verlassen hast.\n"; break;
		case 'b': cout << "Das Bett ist gemacht.\n"; break;
		case 'c': cout << "Das Bett ist total durchwuehlt.\n"; break;
		default: ;
	}
}

void ansehnSchrank()
{	cout << "Hier liegen allerlei nuetzlicher Dinge.\n";}

void ansehnFenster()
{
	srand( (unsigned)time( NULL ) );
	char Fenster=(97+(rand()%10));

	switch(Fenster)
	{
		case 'a': cout << "Die Blumen bluehen.\n";
					Fenster++; break;
		case 'b': cout << "Kondenswasser laeuft an der Scheibe herunter.\n";
					Fenster++; break;
		case 'c': cout << "Voegel ziehen vorueber.\n";
					Fenster++; break;
		case 'd': cout << "Es sind keine Sterne am Himmel.\n";
					Fenster++; break;
		case 'e': cout << "Der Himmel ist hellblau.\n";
					Fenster++; break;
		case 'f': cout << "Es sind keine Wolken am Himmel.\n";
					Fenster++; break;
		case 'g': cout << "Die Sonne scheint.\n";
					Fenster++; break;
		case 'h': cout << "Das Fenster ist dreckig.\n";
					Fenster++; break;
		case 'i': cout << "Eine Katze liegt draussen auf der Fensterbank.\n";
					Fenster++; break;
		case 'j': cout << "Die Sonne blendet.\n";
					Fenster++; break;
		default: ;
	}
}

void ansehnTisch(const char &Tisch)
{	if(Tisch=='a')
	{cout << "Auf dem Tisch herscht Caos.\n";}
	else
	{cout << "Der Tisch ist aufgeraeumt.\n";}
}

void ansehnPC(const char &PC)
{
	if(PC=='a')
	{	cout << "Der PC ist aus.\n";}
	else
	{	cout << "Der PC ist an. Es fehlt der Monitor und die Tastatur. Du hoerst das Summen das Luefters.\n";}
}

void ansehnBuecher()
{
	srand( (unsigned)time( NULL ) );
	char Buecher=(97+(rand()%10));

	switch(Buecher)
	{
		case 'a': cout << "Es gibt die verschiedensten Buecher.\n"; break;
		case 'b': cout << "Da sind AkteX Romane.\n"; break;
		case 'c': cout << "Dort stehen Krimis.\n"; break;
		case 'd': cout << "Einige Bastel- und Experimentierbuecher stehen auch da.\n"; break;
		case 'e': cout << "Verschiedene Wissenschafts- und Technikbuecher sind auch vorhanden.\n"; break;
		case 'f': cout << "Kinderbuecher - wie suess.\n"; break;
		case 'g': cout << "Schullehrbuecher - interessant...\n"; break;
		case 'h': cout << "Maerchen - fuer Gross und Klein.\n"; break;
		case 'i': cout << "Unterschiedliche biblische Lektuere.\n"; break;
		case 'j': cout << "Mosaik-Hefte - ein Sammler.\n"; break;
		default: ;
	}
}

void ansehnTuer(const char &Tuer)
{
	if(Tuer=='a')
	{	cout << "Die Tuer ist verschlossen.\n";}
	else
	{	cout << "Die Tuer ist offen.\n";}
}

void ansehnWand(const char &Wand)
{
	switch(Wand)
	{
		case 'a': cout << "! W-A-N-D !\n"; break;
		case 'b': cout << "!? W-A-N-D ?!\n";break;
		case 'c': cout << "Hm, Wand.\n";break;
		case 'd': cout << "Hey, eine Wand!\n";break;
		case 'e': cout << "Da ist ein Tropfen Blut an der Wand.\n";break;
		case 'f': cout << "Und da noch mehr Bluttropfen.\n";break;
		case 'g': cout << "Hier ist ein groesserer Blutfleck.\n"; break;
		case 'h': cout << "Die Wand hat Farbe bekommen.\n"; break;
		case 'i': cout << "Blut laeuft an der Wand hinunter.\n"; break;
		default: ;
	}
}

void ansehnStuhl()
{	cout << "Der Stuhl sieht bequem aus.\n"; }

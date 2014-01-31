 //**********************************************************************************************//
// Dieses Spiel ist nach dem Sein von KBlackBox entwickelt worden.                                //
// Darum trägt es auch den Namen BB2CON. Aus diesen Gründen steht auch dieses Spiel unter der GPL.//
//																								  //
// Autor: Manuel Bellersen																		  //
// EMail: BellersenM@nerdshack.com																  //
// ICQ:   169472746																				  //
 //**********************************************************************************************//

/*
#include <time.h>
srand( (unsigned)time( NULL ) ); // Initialisiert den Random-Generator mit der akt. Zeit in Sek
und dann einfach
x = rand()%11;*/

#ifdef HAVE_CONFXG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Zeichnen(char Spielbrett[21][21]);

int main(int argc, char *argv[])
{
srand( (unsigned)time( NULL ) );//Random-Zeit
//***************//
// Das Spielbrett //
//***************//
	char Spielbrett[21][21];
	unsigned short int Steinplaziert=0, Laseraktiv=0, Moeglichkeit=0, Fehler=0, SteinX=0, SteinY=0, Gewinn1X=0, Gewinn1Y=0, Gewinn2X=0, Gewinn2Y=0, Gewinn3X=0, Gewinn3Y=0, Gewinn4X=0, Gewinn4Y=0, Richtung=0, AnzahlX=0, AnzahlY=0, Art=0, ArtAnzahl=0;
	bool Spielende=0, Getroffen=0;
	bool Spielfeld[10][10];
	bool Gewinnfeld[10][10];

//Umrandung

	Spielbrett[2][0]='0';
	Spielbrett[4][0]='1';
	Spielbrett[6][0]='2';
	Spielbrett[8][0]='3';
	Spielbrett[10][0]='4';
	Spielbrett[12][0]='5';
	Spielbrett[14][0]='6';
	Spielbrett[16][0]='7';
	Spielbrett[18][0]='8';
	Spielbrett[20][0]='9';

	Spielbrett[0][2]='0';
	Spielbrett[0][4]='1';
	Spielbrett[0][6]='2';
	Spielbrett[0][8]='3';
	Spielbrett[0][10]='4';
	Spielbrett[0][12]='5';
	Spielbrett[0][14]='6';
	Spielbrett[0][16]='7';
	Spielbrett[0][18]='8';
	Spielbrett[0][20]='9';

	Spielbrett[0][0]=' ';
	Spielbrett[2][2]=' ';
	Spielbrett[2][20]=' ';
	Spielbrett[20][2]=' ';
	Spielbrett[20][20]=' ';

	for(unsigned short int X=1;X<21;X=X+2)		//Reihe 1: frei
	{
			Spielbrett[X][0]=' ';
	}
	for(unsigned short int X=1;X<21;X++)		//Reihe 2: leer
	{
			Spielbrett[X][1]=' ';
	}
	for(unsigned short int X=1;X<21;X=X+2)		//Reihe 3: frei
	{
			Spielbrett[X][2]=' ';
	}
	for(unsigned short int X=4;X<20;X=X+2)		//Reihe 3: #
	{
			Spielbrett[X][2]='#';
	}
	for(unsigned short int X=1;X<21;X=X+2)		//Reihe 21: frei
	{
			Spielbrett[X][20]=' ';
	}
	for(unsigned short int X=4;X<20;X=X+2)		//Reihe 21: #
	{
			Spielbrett[X][20]='#';
	}

	for(unsigned short int Y=1;Y<21;Y=Y+2)		//Spalte 1: frei
	{
			Spielbrett[0][Y]=' ';
	}
	for(unsigned short int Y=1;Y<21;Y++)		//Spalte 2: leer
	{
			Spielbrett[1][Y]=' ';
	}
	for(unsigned short int Y=1;Y<21;Y=Y+2)		//Spalte 3: frei
	{
			Spielbrett[2][Y]=' ';
	}
	for(unsigned short int Y=4;Y<20;Y=Y+2)		//Spalte 3: #
	{
			Spielbrett[2][Y]='#';
	}
	for(unsigned short int Y=1;Y<21;Y=Y+2)		//Spalte 21: frei
	{
			Spielbrett[20][Y]=' ';
	}
	for(unsigned short int Y=4;Y<20;Y=Y+2)		//Spalte 21: #
	{
			Spielbrett[20][Y]='#';
	}

//Feldinneres

	for(unsigned short int Y=1;Y<20;Y=Y+2)
	{
		for(unsigned short int X=1;X<20;X=X+2)
		{
			Spielbrett[X][Y]='+';
		}
	}
	for(unsigned short int Y=0;Y<21;Y=Y+2)
	{
		for(unsigned short int X=1;X<21;X=X+2)
		{
			Spielbrett[X][Y]='|';
		}
	}
	for(unsigned short int Y=1;Y<21;Y=Y+2)
	{
		for(unsigned short int X=0;X<21;X=X+2)
		{
			Spielbrett[X][Y]='-';
		}
	}
	for(unsigned short int Y=4;Y<20;Y=Y+2)
	{
		for(unsigned short int X=4;X<20;X=X+2)
		{
			Spielbrett[X][Y]=' ';
		}
	}

	//Spielfeldsäuberung
	for(unsigned short int Y=0;Y<10;Y++)
	{
		for(unsigned short int X=0;X<10;X++)
		{
			Spielfeld[X][Y]=0;
		}
	}

	for(unsigned short int Y=0;Y<10;Y++)
	{
		for(unsigned short int X=0;X<10;X++)
		{
			Gewinnfeld[X][Y]=0;
		}
	}

	for(unsigned short int X=0;X<10;X++)
	{
		Gewinnfeld[X][0]=1;
	}
	for(unsigned short int X=0;X<10;X++)
	{
		Gewinnfeld[X][9]=1;
	}
	for(unsigned short int Y=0;Y<10;Y++)
	{
		Gewinnfeld[0][Y]=1;
	}
	for(unsigned short int Y=0;Y<10;Y++)
	{
		Gewinnfeld[9][Y]=1;
	}

//*******************//
// Das Spiel beginnt //
//*******************//

//Hier kommt dann random rein
//Achtung!: Nicht kleiner 1 und größer 8 !!
Gewinn1X=1+(rand()%8);
Gewinn1Y=1+(rand()%8);
Gewinnfeld[Gewinn1X][Gewinn1Y]=1;

Gewinn2X=1+(rand()%8);
Gewinn2Y=1+(rand()%8);
if(Gewinnfeld[Gewinn2X][Gewinn2Y])
{
	while(Gewinn1X==Gewinn2X && Gewinn1Y==Gewinn2Y)
	{
		Gewinn2X=1+(rand()%8);
		Gewinn2Y=1+(rand()%8);
	}
}

Gewinn3X=1+(rand()%8);
Gewinn3Y=1+(rand()%8);
if(Gewinnfeld[Gewinn3X][Gewinn3Y])
{
	while((Gewinn1X==Gewinn3X && Gewinn1Y==Gewinn3Y) || (Gewinn2X==Gewinn3X && Gewinn2Y==Gewinn3Y))
	{
		Gewinn3X=1+(rand()%8);
		Gewinn3Y=1+(rand()%8);
	}
}

Gewinn4X=1+(rand()%8);
Gewinn4Y=1+(rand()%8);
if(Gewinnfeld[Gewinn4X][Gewinn4Y])
{
	while((Gewinn1X==Gewinn4X && Gewinn1Y==Gewinn4Y) || (Gewinn2X==Gewinn4X && Gewinn2Y==Gewinn4Y) || (Gewinn3X==Gewinn4X && Gewinn3Y==Gewinn4Y))
	{
		Gewinn4X=1+(rand()%8);
		Gewinn4Y=1+(rand()%8);
	}
}

Gewinnfeld[Gewinn1X][Gewinn1Y]=1;
Gewinnfeld[Gewinn2X][Gewinn2Y]=1;
Gewinnfeld[Gewinn3X][Gewinn3Y]=1;
Gewinnfeld[Gewinn4X][Gewinn4Y]=1;


	while(!Spielende)
	{
		Zeichnen(Spielbrett);

//Angabe der Möglichkeiten
		if(Steinplaziert!=4 && Steinplaziert!=0 && Laseraktiv!=32)
		{
			cout << "Moeglichkeiten: Stein plazieren(1), Stein entfernen(2), Laser aktivieren(3), Spiel beenden(0): ";
			cin >> Moeglichkeit;
			Fehler=1;
		}
		else
		{
			if(Steinplaziert==0 && Laseraktiv!=32)
			{
				cout << "Moeglichkeiten: Stein plazieren(1), Laser aktivieren(3), Spiel beenden(0): ";
				cin >> Moeglichkeit;
				Fehler=2;
			}
			else
			{
				if(Steinplaziert==4 && Laseraktiv!=32)
				{
					cout << "Moeglichkeiten: Stein entfernen(2), Laser aktivieren(3), Raetsel loesen(4) Spiel beenden(0): ";
					cin >> Moeglichkeit;
					Fehler=3;
				}
				else
				{
					if(Steinplaziert==0 && Laseraktiv==32)
					{
						cout << "Moeglichkeiten: Stein plazieren(1), Spiel beenden(0): ";
						cin >> Moeglichkeit;
						Fehler=4;
					}
					else
					{
						if(Steinplaziert==4 && Laseraktiv==32)
						{
							cout << "Moeglichkeiten: Stein entfernen(2), Raetsel loesen(4), Spiel beenden(0): ";
							cin >> Moeglichkeit;
							Fehler=5;
						}
						else
						{
							if(Steinplaziert!=4 && Steinplaziert!=0 && Laseraktiv==32)
							{
								cout << "Moeglichkeiten: Stein plazieren(1), Stein entfernen(2), Spiel beenden(0): ";
								cin >> Moeglichkeit;
								Fehler=6;
							}
						}
					}
				}
			}
		}

//Abfrage der Antwort auf Fehler und Auswertung
		switch(Moeglichkeit)
		{
			case 0:	exit(1);
					break;
			case 1:	//Stein platzieren
					if(Fehler==1 || Fehler==2 || Fehler==4 || Fehler==6)
					{
						cout << "Wohin wollen sie den Stein setzen? X: ";
						cin >> SteinX;
						cout << "Y: ";
						cin >> SteinY;
						if(SteinX<1 || SteinX>8 || SteinY<1 || SteinY>8)
						{
							cout << "Dort kann kein Stein hingelegt werden.\n";
						}
						else
						{
							if(Spielfeld[SteinX][SteinY])
							{
								cout << "Dort liegt schon ein Stein.\n";
							}
							else
							{
								Spielfeld[SteinX][SteinY]=1;
								Spielbrett[SteinX*2+2][SteinY*2+2]='o';
								Steinplaziert++;
								cout << "Stein wurde auf X: " << SteinX << " Y: " << 	SteinY << " plaziert.\n";
							}
						}
					}
					else
						cout << "Fehler bei der Eingabe\n";
					break;
			case 2:	//Stein entfernen
					if(Fehler==1  || Fehler==3 || Fehler==5 || Fehler==6)
					{
						cout << "Welchen Stein moechten sie entfernen? X: ";
						cin >> SteinX;
						cout << "Y: ";
						cin >> SteinY;
						if(!Spielfeld[SteinX][SteinY] || SteinX<1 || SteinX>8 || SteinY<1 || SteinY>8)
						{
							cout << "Dort liegt kein Stein.\n";
						}
						else
						{
							Spielfeld[SteinX][SteinY]=0;
							Spielbrett[SteinX*2+2][SteinY*2+2]=' ';
							Steinplaziert--;
							cout << "Stein wurde von X: " << SteinX << " Y: " << SteinY << " entfernt.\n";
						}
					}
					else
						cout << "Fehler bei der Eingabe\n";
					break;
			case 3:	//Laser aktivieren
					if(Fehler==1  || Fehler==2 || Fehler==3)
					{
						cout << "Welchen Laser wollen sie aktivieren? X: ";
						cin >> SteinX;
						cout << "Y: ";
						cin >> SteinY;
						if(SteinX<0 || SteinX>9 || SteinY<0 || SteinY>9)
						{
							cout << "Dort ist kein Laser.\n";
						}
						else
						{
							if(((SteinX==0 || SteinX==9)&& (SteinY>0 && SteinY<9)) || ((SteinY==0 || SteinY==9) && (SteinX>0 && SteinX<9)))
							{
								if(Spielfeld[SteinX][SteinY])
								{
									cout << "Der Laser ist bereits aktiviert.\n";
								}
								else	////Richtungsabfrage, Kollision
								{
									if(SteinX==0)//l->r
										Richtung=1;

									if(SteinX==9)//r->l
										Richtung=3;

									if(SteinY==0)//o->u
										Richtung=2;

									if(SteinY==9)//u->o
										Richtung=4;

									AnzahlX=SteinX;
									AnzahlY=SteinY;
									Getroffen=0;

									while(!Getroffen)
									{
										switch(Richtung)
										{
											case 1://l->r
													if(Gewinnfeld[AnzahlX+1][AnzahlY])
													{
														if((AnzahlX+1)==9)
														{
															AnzahlX++;
															Art=1;
															Getroffen=1;;
														}
														else
														{
															Art=2;
															Getroffen=1;
														}
													}
													else
													{
														if(Gewinnfeld[AnzahlX+1][AnzahlY-1] && Gewinnfeld[AnzahlX+1][AnzahlY+1])
														{
															if((AnzahlY-1)!=0 && (AnzahlY+1)!=9)
															{
																Art=3;
																Getroffen=1;
															}
															else
															{
																if((AnzahlY-1)==0)
																	Richtung=4;
																else
																{
																	if((AnzahlY+1)==9)
																		Richtung=2;
																	else
																	{cout << "Fehler:l->r\n"; exit(1);}
																}
															}
														}
														else
														{
															if(Gewinnfeld[AnzahlX+1][AnzahlY-1])
															{
																if((AnzahlY-1)==0)
																	AnzahlX++;
																else
																{
																	if(AnzahlX==0)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=2;
																}
															}
															else
															{
																if(Gewinnfeld[AnzahlX+1][AnzahlY+1])
																{
																	if((AnzahlY+1)==9)
																		AnzahlX++;
																	else
																	{
																	if(AnzahlX==0)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=4;
																	}
																}
																else
																	AnzahlX++;
															}
														}
													}
													break;
											case 2://o->u
													if(Gewinnfeld[AnzahlX][AnzahlY+1])
													{
														if((AnzahlY+1)==9)
														{
															AnzahlY++;
															Art=1;
															Getroffen=1;;
														}
														else
														{
															Art=2;
															Getroffen=1;
														}
													}
													else
													{
														if(Gewinnfeld[AnzahlX-1][AnzahlY+1] && Gewinnfeld[AnzahlX+1][AnzahlY+1])
														{
															if((AnzahlX-1)!=0 && (AnzahlX+1)!=9)
															{
																Art=3;
																Getroffen=1;
															}
															else
															{
																if((AnzahlX-1)==0)
																	Richtung=3;
																else
																{
																	if((AnzahlX+1)==9)
																		Richtung=1;
																	else
																	{cout << "Fehler:o->u\n"; exit(1);}
																}
															}
														}
														else
														{
															if(Gewinnfeld[AnzahlX-1][AnzahlY+1])
															{
																if((AnzahlX-1)==0)
																	AnzahlY++;
																else
																{
																	if(AnzahlY==0)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=1;
																}
															}
															else
															{
																if(Gewinnfeld[AnzahlX+1][AnzahlY+1])
																{
																	if((AnzahlX+1)==9)
																		AnzahlY++;
																	else
																	{
																	if(AnzahlY==0)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=3;
																	}
																}
																else
																	AnzahlY++;
															}
														}
													}
													break;
											case 3://r->l
													if(Gewinnfeld[AnzahlX-1][AnzahlY])
													{
														if((AnzahlX-1)==0)
														{
															AnzahlX--;
															Art=1;
															Getroffen=1;;
														}
														else
														{
															Art=2;
															Getroffen=1;
														}
													}
													else
													{
														if(Gewinnfeld[AnzahlX-1][AnzahlY-1] && Gewinnfeld[AnzahlX-1][AnzahlY+1])
														{
															if((AnzahlY-1)!=0 && (AnzahlY+1)!=9)
															{
																Art=3;
																Getroffen=1;
															}
															else
															{
																if((AnzahlY-1)==0)
																	Richtung=4;
																else
																{
																	if((AnzahlY+1)==9)
																		Richtung=2;
																	else
																	{cout << "Fehler:r->l\n"; exit(1);}
																}
															}
														}
														else
														{
															if(Gewinnfeld[AnzahlX-1][AnzahlY-1])
															{
																if((AnzahlY-1)==0)
																	AnzahlX--;
																else
																{
																	if(AnzahlX==9)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=2;
																}
															}
															else
															{
																if(Gewinnfeld[AnzahlX-1][AnzahlY+1])
																{
																	if((AnzahlY+1)==9)
																		AnzahlX--;
																	else
																	{
																	if(AnzahlX==9)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=4;
																	}
																}
																else
																	AnzahlX--;
															}
														}
													}
													break;
											case 4://u->o
													if(Gewinnfeld[AnzahlX][AnzahlY-1])
													{
														if((AnzahlY-1)==0)
														{
															AnzahlY--;
															Art=1;
															Getroffen=1;;
														}
														else
														{
															Art=2;
															Getroffen=1;
														}
													}
													else
													{
														if(Gewinnfeld[AnzahlX-1][AnzahlY-1] && Gewinnfeld[AnzahlX+1][AnzahlY-1])
														{
															if((AnzahlX-1)!=0 && (AnzahlX+1)!=9)
															{
																Art=3;
																Getroffen=1;
															}
															else
															{
																if((AnzahlX-1)==0)
																	Richtung=3;
																else
																{
																	if((AnzahlX+1)==9)
																		Richtung=1;
																	else
																	{cout << "Fehler:u->o\n"; exit(1);}
																}
															}
														}
														else
														{
															if(Gewinnfeld[AnzahlX-1][AnzahlY-1])
															{
																if((AnzahlX-1)==0)
																	AnzahlY--;
																else
																{
																	if(AnzahlY==9)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=1;
																}
															}
															else
															{
																if(Gewinnfeld[AnzahlX+1][AnzahlY-1])
																{
																	if((AnzahlX+1)==9)
																		AnzahlY--;
																	else
																	{
																	if(AnzahlY==9)
																	{
																		Art=3;
																		Getroffen=1;
																	}
																	else
																		Richtung=3;
																	}
																}
																else
																	AnzahlY--;
															}
														}
													}
													break;
											default:
													break;
										}
									}

									switch(Art)
									{
										case 1: Spielbrett[SteinX*2+2][SteinY*2+2]=(ArtAnzahl+97);
												Spielfeld[SteinX][SteinY]=1;
												Spielbrett[AnzahlX*2+2][AnzahlY*2+2]=(ArtAnzahl+97);
												Spielfeld[AnzahlX][AnzahlY]=1;
												ArtAnzahl++;
												Laseraktiv++;
												Laseraktiv++;
												break;
										case 2: Spielbrett[SteinX*2+2][SteinY*2+2]='T';
												Spielfeld[SteinX][SteinY]=1;
												Laseraktiv++;
												break;
										case 3: Spielbrett[SteinX*2+2][SteinY*2+2]='R';
												Spielfeld[SteinX][SteinY]=1;
												Laseraktiv++;
												break;
										default:break;
									}
									cout << "Laser auf X: " << SteinX << " Y: " << 	SteinY << " wurde aktiviert.\n";
								}
							}
							else
								cout << "Dort ist kein Laser.\n";
						}
					}
					else
						cout << "Fehler bei der Eingabe\n";
					break;
			case 4:	//Raetsel loesen
					if(Fehler==3 || Fehler==5)
					{
						Spielende=1;
					}
					else
						cout << "Fehler bei der Eingabe\n";
					break;
			default:
					cout << "Fehler bei der Eingabe\n";
					break;
		}
	}

	Zeichnen(Spielbrett);

//*****************//
// Spielauswertung //
//*****************//

	if(Spielfeld[Gewinn1X][Gewinn1Y] && Spielfeld[Gewinn2X][Gewinn2Y] && Spielfeld[Gewinn3X][Gewinn3Y] && Spielfeld[Gewinn4X][Gewinn4Y])
	{
		cout << "Gluekwunsch! Sie haben gewonnen!\n";
	}
	else
	{
		cout << "Sie haben leider verloren.\n";
		cout << "Die Orte der Kugeln waren\n";
		cout << "X1: " << Gewinn1X << " Y1: " << Gewinn1Y << endl;
		cout << "X2: " << Gewinn2X << " Y2: " << Gewinn2Y << endl;
		cout << "X3: " << Gewinn3X << " Y3: " << Gewinn3Y << endl;
		cout << "X4: " << Gewinn4X << " Y4: " << Gewinn4Y << endl;
	}

  return EXIT_SUCCESS;
}

void Zeichnen(char Spielbrett[21][21])
{
	for(unsigned short int Y=0;Y<21;Y++)
	{
		for(unsigned short int X=0;X<21;X++)
		{
			cout << Spielbrett[X][Y];
		}
		cout << endl;
	}
}

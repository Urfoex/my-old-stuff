#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "SDL.h"

#define Fensterbreite 400
#define Fensterhoehe 300

using namespace std;

class Vektor3D
{
	public:		Vektor3D(short int getX, short int getY, short int getZ);
				Vektor3D(short int getX1, short int getY1, short int getZ1, short int getX2, short int getY2, short int getZ2);
				short int rX(){return X;}; //r-> return
				short int rY(){return Y;};
				short int rZ(){return Z;};
				void changeX(short int getX=0){X=getX; Betrag=sqrt((X*X)+(Y*Y)+(Z*Z));};
				void changeY(short int getY=0){Y=getY; Betrag=sqrt((X*X)+(Y*Y)+(Z*Z));};
				void changeZ(short int getZ=0){Z=getZ; Betrag=sqrt((X*X)+(Y*Y)+(Z*Z));};
				float rBetrag(){return Betrag;};

	protected:
	private:	short int X,Y,Z;
				float Betrag;
};

Vektor3D::Vektor3D(short int getX, short int getY, short int getZ)
{
	X=getX;
	Y=getY;
	Z=getZ;
	Betrag=sqrt((X*X)+(Y*Y)+(Z*Z));
}

Vektor3D::Vektor3D(short int getX1, short int getY1, short int getZ1, short int getX2, short int getY2, short int getZ2)
{
	X=getX2-getX1;
	Y=getY2-getY1;
	Z=getZ2-getZ1;
	Betrag=sqrt((X*X)+(Y*Y)+(Z*Z));
}


int main(int argc, char *argv[])
{
	cout << "...ProjektAlpha startet...\n";
	cout << "      ...Loading...\n";

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK)<0)
	{
		cout << "Konnte SDL nicht laden: " << SDL_GetError() << endl;;
		SDL_Quit();
		exit(-1);
	}
	else
	{	cout << "SDL geladen...\n";}

	SDL_Surface *Display = SDL_SetVideoMode( Fensterbreite , Fensterhoehe ,16, SDL_HWSURFACE | SDL_HWACCEL | SDL_DOUBLEBUF);

	if(!Display)
	{
		cout << "Konnte Display nicht starten: " << SDL_GetError() << endl;
		SDL_Quit();
		exit(-1);
	}
	else
	{	cout << "Display gestartet...\n";	}

	SDL_Event Event;

	int NummerJoystick = SDL_NumJoysticks();
	if(NummerJoystick)
	{
		if(NummerJoystick==1)
		{
			SDL_Joystick *Joystick = SDL_JoystickOpen(0);
			if(Joystick==NULL)
			{
				cout << "Kann nicht auf Joystick zugreifen: " << NummerJoystick << SDL_GetError() << endl;
				SDL_Quit();
				exit(-1);
			}
			else
			{	cout << "Joystick aktiv...\n";	}
		}
		else
		{
			unsigned short int NumJoy=0;
			cout << "Mit welchem Joystick wollen sie spielen? (" << NummerJoystick << " vorhanden): ";
			cin >> NumJoy;

			SDL_Joystick *Joystick = SDL_JoystickOpen(NumJoy);
			if(Joystick==NULL)
			{
				cout << "Kann nicht auf Joystick zugreifen: " << NummerJoystick << SDL_GetError() << endl;
				SDL_Quit();
				exit(-1);
			}
			else
			{	cout << "Joystick aktiv...\n";	}
		}
	}
	else
	{
		cout << "Kein Joystick vorhanden\n";
		SDL_Quit();
		exit(-1);
	}

	while(SDL_PollEvent(&Event))
	{	cout << "Entleere Events: " << Event.type << endl;	}



	bool Ende=0;
	SDL_Surface *BlackBild = SDL_LoadBMP("grafiken/blackplop.bmp");
	SDL_Surface *WhiteBild = SDL_LoadBMP("grafiken/whiteplop.bmp");
	SDL_Surface *BackBild = SDL_LoadBMP("grafiken/back.bmp");

	if(!BlackBild || !WhiteBild || !BackBild)
	{
		cout << "Bildfehler" << SDL_GetError() << endl;
		SDL_Quit();
		exit(-1);
	}

	SDL_Rect JoyXY;
	char Achsen[2];
	char Achsen2[2];
	bool Tasten[12];
	char Sprung;

	cout << "Daten geladen...\n";

	SDL_BlitSurface(BackBild,NULL,Display,NULL);
	
	JoyXY.x=0;
	JoyXY.y=0;
	JoyXY.h=1;
	JoyXY.w=1;
	SDL_BlitSurface(BackBild,&JoyXY,BlackBild,NULL);

	Achsen[0]=49; //1
	Achsen[1]=49;
	Achsen2[0]=49;
	Achsen2[1]=49;
	for(unsigned short int I=0; I<12;I++)
	{	Tasten[I]=0;	}
	Sprung=48;

	cout << "Daten initialisiert...\n";

	cout << "ProjektAlpha: gestartet...\n";

	Vektor3D Eins(4,0,0);
	Vektor3D Zwei(-1,0,0,-5,0,0);
	Vektor3D Drei(Eins.rX(),Eins.rY(),Eins.rZ(),Zwei.rX(),Zwei.rY(),Zwei.rZ());
	cout << Eins.rBetrag() << endl << Zwei.rBetrag() << endl << Drei.rBetrag() << endl;

	while(!Ende)
	{

		while(SDL_PollEvent(&Event))
		{
			switch(Event.type)
			{
				case SDL_JOYAXISMOTION:	if(Event.jaxis.axis==0 && Event.jaxis.value>0)	Achsen[0]=50;
										if(Event.jaxis.axis==0 && Event.jaxis.value<0)	Achsen[0]=48;
										if(Event.jaxis.axis==0 && Event.jaxis.value==0)	Achsen[0]=49;
										if(Event.jaxis.axis==1 && Event.jaxis.value>0)	Achsen[1]=50;
										if(Event.jaxis.axis==1 && Event.jaxis.value<0)	Achsen[1]=48;
										if(Event.jaxis.axis==1 && Event.jaxis.value==0)	Achsen[1]=49;

										break;
				case SDL_JOYBUTTONDOWN:	
										if(Event.jbutton.button==9)	Ende=1;
										if(Event.jbutton.button==0)	Tasten[0]=1;
										break;
				case SDL_JOYBUTTONUP:	
										break;
				default:				break;
			}
		}

		SDL_BlitSurface(BlackBild,NULL,Display,&JoyXY);

		if(Tasten[0]==1)
		{
			if((Achsen[0]==48) && (Achsen2[0]!=50 && Sprung==48))	Achsen2[0]=48;
			if((Achsen[0]==50) && (Achsen2[0]!=48 && Sprung==48))	Achsen2[0]=50;

			if(Sprung<57)	JoyXY.y--;
			if(Sprung>56)	JoyXY.y++;

			if(Achsen2[0]==48)	JoyXY.x--;
			else if(Achsen2[0]==50)	JoyXY.x++;

			if(Sprung==65)
			{
				Achsen2[0]=49;
				Sprung=47;
				Tasten[0]=0;
			}
			Sprung++;
		}

		if(Achsen2[0]==49)
		{
			if(Achsen[0]==48)	JoyXY.x--;
			if(Achsen[0]==50)	JoyXY.x++;
			if(Achsen[1]==48)	JoyXY.y--;
			if(Achsen[1]==50)	JoyXY.y++;
		}



		if(JoyXY.x>Fensterbreite-1)	JoyXY.x=Fensterbreite-1;
		if(JoyXY.y>Fensterhoehe-1)	JoyXY.y= Fensterhoehe-1;
		if(JoyXY.x<0)	JoyXY.x=0;
		if(JoyXY.y<0)	JoyXY.y=0;

		SDL_BlitSurface(Display,&JoyXY,BlackBild,NULL);
		SDL_BlitSurface(WhiteBild,NULL,Display,&JoyXY);
		SDL_Flip(Display);
	}

	cout << "\nBeende ProjektAlpha...\n";
	SDL_Quit();
	cout << "ProjektAlpha: geschlossen.\n";
	return 0;
}

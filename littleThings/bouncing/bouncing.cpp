#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

using namespace std;

#include "Lebewesen.h"

class Mapping
{
public:
	Mapping(unsigned short int IX=0, unsigned short int IY=0);
	void getAddresse(unsigned short int &IX, unsigned short int &IY);

	void setX( const unsigned short int& theValue );
	unsigned short int getX() const;

	void setY( const unsigned short int& theValue );
	unsigned short int getY() const;
	
	

private:
	unsigned short int X,Y;


};

Mapping::Mapping(unsigned short int IX, unsigned short int IY)
{

	X=IX;
	Y=IY;
}

unsigned short int Mapping::getX() const
{	return X; }

void Mapping::setX( const unsigned short int& theValue )
{	X = theValue; }

unsigned short int Mapping::getY() const
{	return Y; }

void Mapping::setY( const unsigned short int& theValue )
{	Y = theValue; }

void Mapping::getAddresse(unsigned short int &IX, unsigned short int &IY)
{
	IX=0;
	IY=0;
}


int main(int argc, char *argv[])
{
	Lebewesen Spieler(100,11);
	Lebewesen Gegenspieler(50,2);
	Gegenspieler.setPosX(Gegenspieler.getPosX()+5);
	Gegenspieler.setTyp(0);

	Lebewesen *Addresse;

	char IsoMap[10][10];
	for(unsigned short int IX=0;IX<10;IX++)
	{
		for(unsigned short int IY=0;IY<10;IY++)
		{	IsoMap[IX][IY]=' '; }
	}

	//??? AddMap[10][10];
	for(unsigned short int IX=0;IX<10;IX++)
	{
		for(unsigned short int IY=0;IY<10;IY++)
		{	IsoMap[IX][IY]=' '; }
	}

	IsoMap[Spieler.getPosX()][Spieler.getPosY()]=='S';
	IsoMap[Gegenspieler.getPosX()][Gegenspieler.getPosY()]='G';

	
	Mapping Maps(10, 10);



	while(Gegenspieler.getLeben()>0)
	{

	if(IsoMap[Spieler.getPosX()+1][Spieler.getPosY()]!=' ')
	{
	//	Addresse=??;
		
		if(Spieler.getPosX()==(Gegenspieler.getPosX()-1))
		{
			Spieler.setLeben(Spieler.getLeben()-Gegenspieler.getSchaden());
			Gegenspieler.setLeben(Gegenspieler.getLeben()-Spieler.getSchaden());
		}
		else
		{
			IsoMap[Spieler.getPosX()][Spieler.getPosY()]=' ';
			Spieler.setPosX(Spieler.getPosX()+1);
			IsoMap[Spieler.getPosX()][Spieler.getPosY()]='S';
		}
		cout << endl << "Spieler: " << Spieler.getLeben() << endl;
		cout << "SX: " << Spieler.getPosX() << "SY: " << Spieler.getPosY() << endl;
		cout << "Gegenspieler: " <<Gegenspieler.getLeben() <<  endl;

	}
	else
		Spieler.setPosX(Spieler.getPosX()+1);
	}

	return EXIT_SUCCESS;
}




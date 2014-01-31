#include <iostream>

using namespace std;

class Auto
{
 public:
        Auto():Geschwindigkeit(0){};
        void beschleunigen(const signed short int &Var);
        void Handbremse();
        const signed short int getGeschwindigkeit(){return Geschwindigkeit;};

 protected:
        signed short int Geschwindigkeit;
};

void Auto::beschleunigen(const signed short int &Var)
{    Geschwindigkeit+=Var;    }

void Auto::Handbremse()
{
    while(Geschwindigkeit)
    {
        if(getGeschwindigkeit()>0)
            beschleunigen(-1);
        else
            beschleunigen(+1);
    }
}

class Audi : public Auto
{
 public:
		Audi():Licht(0){};
        void Lichtschalter();
        const bool Lichtstatus(){return Licht;};
		void Speed();
 protected:
        bool Licht;
};

void Audi::Lichtschalter()
{
    if(Licht)
        Licht=0;
    else
        Licht=1;
}

void Audi::Speed()
{
	if(Geschwindigkeit>=200)
	{cout <<"Speedfreak\n" ;}
	else
	{++Geschwindigkeit;}
}


int main()
{
    Auto BMW;
    Audi A4;
	bool GameNotEnd=1;
	unsigned short int Zaehler=0;

    BMW.beschleunigen(100);
    BMW.beschleunigen(100);
    cout << "Geschwindigleit: " << BMW.getGeschwindigkeit() << endl;
    BMW.Handbremse();
    cout << "Geschwindigleit: " << BMW.getGeschwindigkeit() << endl;

    cout << "Lichtstatus: " << A4.Lichtstatus() << endl;
    A4.Lichtschalter();
    cout << "Lichtstatus: " << A4.Lichtstatus() << endl;

    A4.beschleunigen(100);
    cout << "Geschwindigleit: " << A4.getGeschwindigkeit() << endl;
    A4.Handbremse();
    cout << "Geschwindigleit: " << A4.getGeschwindigkeit() << endl;

while(GameNotEnd)
{
	A4.Speed();
	cout << "A4: " << A4.getGeschwindigkeit() << endl;
	if(Zaehler==202)
		GameNotEnd=0;
	++Zaehler;
}


    return 0;
}

#include <iostream.h>

class Sonderzeichen  
{
public:
	Position(int Zahl);
	Zeichen();

private:
	int Wert;
	char zwer;
};

Sonderzeichen::Position(int Zahl)
{
	Wert=Zahl;
}

Sonderzeichen::Zeichen()
{
	zwer=Wert;
	cout <<  "\n-----> " <<zwer << " <-----" << endl ;
}

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
	cout << "123456789___" <<zwer << "___987654321" << endl ;
}
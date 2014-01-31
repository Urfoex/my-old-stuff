#include "Sonderzeichen.h"

int main()
{
	int Zahlig,ja;
	Sonderzeichen Zeichen;

	cout << "Hallo Mensch !\nDieses Programm gibt für beliebige Zahlen den dazugehöriegen ASCII Codes an.\n";
	cout << "Bitte geben sie die gewünschte Zahl ein :  ";
	cin >> Zahlig;

	Zeichen.Position(Zahlig);
	Zeichen.Zeichen();

	cout << "\nNochmal ?  ";
	cin >> ja;
	if (ja==1)
		main();
	else
		return 0;
	return 0;
}
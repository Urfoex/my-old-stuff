#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	long int liN;
	long int liCache;
	bool bChange;

	do{
	cout << "Wie viel Zahlen wollen sie sortieren? (min. 2, max. 1Vorzeichen): ";
	cin >> liN;
	}
	while(liN<2);

	long int liZahlen[liN];

	cout << "Bitte geben sie nun ihre Zahlen durch ENTER getrennt an:\n";

	for(unsigned long int uliI=0; uliI < liN; uliI++)
	{
		cin >> liZahlen[uliI];
	}

	do
	{
		bChange=0;
		for(unsigned long int I=0; I < (liN-1); I++)
		{
			if(liZahlen[I]>liZahlen[I+1])
			{
				liCache=liZahlen[I];
				liZahlen[I]=liZahlen[I+1];
				liZahlen[I+1]=liCache;
				bChange=1;
			}
		}
	}
	while(bChange);

	cout << "Vielen dank.\nHier ihre sortierten Zahlen:\n";

	for(unsigned long int uliI=0; uliI < liN; uliI++)
	{
		cout << liZahlen[uliI] << endl;
	}

	return EXIT_SUCCESS;
}

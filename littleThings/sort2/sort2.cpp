#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	long int liN;
	bool bChange=1;

	do{
	cout << "Wie viel Zahlen wollen sie sortieren? (min. 2): ";
	cin >> liN;
	}
	while(liN<2);

	long int liZahlen[liN];
	long int liCache1[liN];
	long int liCache2[liN];
	unsigned long int uliRange=liN/2;
	if(!(liN%2))
		uliRange=uliRange-1;
	unsigned long int A=0;
	unsigned long int B=0;
	long int liRanZ=0;

	cout << "Bitte geben sie nun ihre Zahlen durch ENTER getrennt an:\n";

	for(unsigned long int uliI=0; uliI < liN; uliI++)
		cin >> liZahlen[uliI];
	do
	{
		A=0;
		B=0;
		liRanZ=liZahlen[uliRange];

			for(unsigned long int I=0; I<liN; I++)
			{

				if(liZahlen[I]<liRanZ)
				{
					liCache1[A]=liZahlen[I];
					A++;
				}
				else
				{
					if(liZahlen[I]>liRanZ)
					{
						liCache2[B]=liZahlen[I];
						B++;
					}
				}
			}

			if(bChange)
			{
				for(unsigned long int C=0; C<A; C++)
				{
					liZahlen[C]=liCache1[C];
				}

				liZahlen[A]=liRanZ;
	
				for(unsigned long int E=0; E<B; E++)
				{
					liZahlen[A+1+E]=liCache2[E];
				}
			}
		unsigned long int uliT=0;
		for(unsigned long int K=0; K < (liN-1); K++)
		{

			if(liZahlen[K]>liZahlen[K+1])
				uliT++;
			if(!uliT)
				bChange=0;
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

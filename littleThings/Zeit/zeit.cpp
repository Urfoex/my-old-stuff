////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                            */
/*     Diese Programm wurde von Manuel Bellersen alias Kakarott geschrieben.                  */
/*     Es zeigt, wie 2 Zeiten addiert werden können.                                          */
/*                                                                                            */
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream.h>

void zeit();


int main()
{

	int z;

	cout << "Hallo, dies Programm rechnet 2 Zeiten zusammen" << endl ;
	z=1;
	while (z>0)
	{
	zeit();
	cout << endl << endl<< "Nochmal(0/1)? ";
	cin >> z;
	}

	return 0;
}

void zeit()
{
	unsigned long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	cout << endl << "Bitte eine Zeit (h-min-s) eingeben: " << endl ;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << endl << endl << "Bitte noch eine Zeit: " << endl ;
	cin >> d;
	cin >> e;
	cin >> f;


	g=a+d;
	h=b+e;
	i=c+f;

	j=i/60;
	i%=60;

	h+=j;
	j=h/60;
	h%=60;

	g+=j;
	j=g/24;
	g%=24;


	k+=j;
	j=k/7;
	k%=7;

	l+=j;
	j=l/52;
	l%=52;


	cout << endl << j << "Jahre " << l << "Wochen " << k << "Tage  " << g << "Stunden " << h << "Minuten " << i << "Sekunden ist die addierte Zeit" << endl ; 
}
#include <iostream.h>
#include "huepfer.h"

int huepfer();

int main()
{
	int a,b,c;
	c=1;
	
	while(c!=0)
	{



		cout << "X(1-80): ";
		cin >> a;

		if (a>80)
			a=80;

		cout << "Y(1-19): ";
		cin >> b;
	
		if (b>19)
			b=19;

		huepfer(a,b);

		cout << endl << "-->> Nochmal?(N-0;J-1): ";
		cin >> c;
	}

	return 0;
}



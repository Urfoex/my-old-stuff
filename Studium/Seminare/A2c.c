#include <stdio.h>

int main( int argc, char *argv[]){
	unsigned long int x=0, n=0;
	char var[64], i = 0;
	while(i<64) var[i++] = 0;
	printf("Eingabe von x,n: ");
	scanf("%d,%d", &x, &n);
	do{
		var[--i] = x%n;
	}while(x/=n && i );
	
	while(i<63){
		printf("%d", var[i++]);
	}




	return 0;
}

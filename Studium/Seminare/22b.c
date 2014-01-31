#include <stdio.h>
#include <math.h>

int main( int argc, char* argv[]){
	unsigned long int n = 0, i = 0;
	printf("Zu pruefende Zahl: ");
	scanf("%lu", &n);
	if( n < 2){
		printf("%lu ist keine Primzahl.\n", n);
		return 0;
	}
	if( !(n % 2) && n != 2){
		printf("%lu ist keine Primzahl. Teiler: 2\n", n);
		return 0;
	}
	for( i = 3; i <= sqrt( n); i += 2){
		if( !( n % i)){
			printf("%lu ist keine Primzahl. Teiler: %lu\n", n, i);
			return 0;
		}
	}
	printf("%lu ist eine Primzahl.\n", n);
 
	return 0;
}

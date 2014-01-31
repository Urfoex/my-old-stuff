#include <stdio.h>

unsigned long long int fibrek( char n){
	unsigned long long int k = 1, j = 1, i = 1;

	for( ; n > 2; --n){
		k = i;
		i += j;
		j = k;
	}
	return i;
}
	
int main( int argc, char* argv[]){
	unsigned short i = 2;
	for( i = 2; i < 100; ++i)
		printf("f(%hd): %llu\n", i, fibrek(i));
	return 0;
}

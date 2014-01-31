#include <stdio.h>

unsigned long long int fibrek( unsigned char Zahl){
	if( Zahl == 1) return 1;
	if( Zahl == 0) return 0;
	return (fibrek( Zahl - 1) + fibrek( Zahl - 2));
}

int main( int argc, char* argv[]){
	short i = 0;
	for( i = 2; i < 50; ++i){
		printf("f(%hd): %d\n", i,fibrek(i));	
	}
	
	return 0;
}

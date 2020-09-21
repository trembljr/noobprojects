#include <stdio.h>
#include <math.h>
#include <string.h>

void main(){
	char binaryNumber[32];
	int decimalVal = 0;
	printf("Enter a binary number:\n");
	scanf(" %s", &binaryNumber);
	for(int i = 0; i < strlen(binaryNumber); ++i){
		if(binaryNumber[i] == '1')
			decimalVal += pow(2,i);
	}
	printf("The decimal value is %d",decimalVal);
}
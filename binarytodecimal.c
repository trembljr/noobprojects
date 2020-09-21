#include <stdio.h>
#include <math.h>
#include <string.h>

void main(int argc, char** argv){
	char binaryNumber[32];
	int decimalVal;
	printf("%d",argc);
	if (argc > 1)
		strcpy(binaryNumber,argv[1]);
	else{
		printf("Enter a binary number:\n");
		scanf(" %s", binaryNumber);
	}
	for(int i = 0; i < strlen(binaryNumber); ++i){
		if(binaryNumber[strlen(binaryNumber)-i-1] == '1')
			decimalVal += pow(2,i);
	}
	printf("%d", decimalVal);
	
}
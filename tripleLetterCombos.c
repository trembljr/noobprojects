#include <stdio.h>

int main(){
	char letter1;
	char letter2;
	char letter3;
	int howMany= 0;
	
	for (letter1 = 'a'; letter1 <= 'z'; ++letter1){
		for (letter2 = 'a' ; letter2 <='z'; ++letter2){
			for (letter3 = 'a' ; letter3 <= 'z'; ++letter3){
				howMany += 1;
				printf("%c%c%c, %d combinations\n",letter1,letter2,letter3, howMany);
			}
		}
	}
}

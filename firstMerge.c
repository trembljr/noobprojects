#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(char board[30][80]);
void UpdateBoard(char words[],char board[30][80]);
void MoveWords(char board[30][80]);
void generateWord(FILE *fileName, char* randomWords);

int main(){
	char playOrAdd;
	char userAddWord[10];
	char board[30][80];
	char userWants;
	int wordLeft;
	char tempWordVar[50];
	for(int w = 0; w < 30; w++){
		for(int i = 0; i < 80; i++){
			board[w][i] = ' ';
		}
	}
	FILE *fp = fopen("wordList.txt", "r+");
	printf("Hello, this is a typing game. You will need to type the words as they" 
	"appear.\nWould you like to play or add a word?\nYou currently have %d words that can" 
    "be used. (Type ‘p’ for play or ‘a’ to add words)", wordLeft);
    scanf(" %c", &playOrAdd);
    srand(time(NULL));
	printf("Enter p to play or anything else to exit\n");
	scanf(" %c", &userWants);
	while(playOrAdd == 'a'){
		fclose(fp);
        FILE *fp = fopen("wordList.txt", "a+");
        printf("Type a word that you want to add(one word, no spaces)\n");
		scanf(" %s",userAddWord);
		fprintf(fp, "\n");
		fprintf(fp, "%s", userAddWord);  //make word go to file
		printf("Your word has been added.\n Would you like to add another word? (Type "
        "'p' or 'a')\n");
		scanf(" %c", &playOrAdd);
	}
	
	while(userWants == 'p'){
		generateWord(fp, &tempWordVar);
		UpdateBoard(tempWordVar, board);
		printf("Enter p to keep playing\n");
		scanf(" %d", &userWants);
	}	
}

void PrintBoard(char board[30][80]){
	printf(" ");
	for(int j = 0; j < 8; j++)
		printf("----------");
	printf("\n");
	for(int i = 0; i < 30; i++){
		printf("|");
		for(int w = 0; w < 80; w++){
			printf("%c", board[i][w]);
			if(w == 79)
				printf("|\n");
		}
	}
}

void UpdateBoard(char words[],char board[30][80]){
	int length = 0;
	int i = 0;
	while(words[i] != '\0'){
	    length++;
	    i++;
	}
	int temp = rand() % 20; //need to add a strlen() function to make it the proper size from the end of the board
	MoveWords(board);
	for(int i = 0; i < length; i++){
		board[0][temp+i] = words[i];
	}
	PrintBoard(board);
}

void MoveWords(char board[30][80]){
	for(int i = 29; i >= 0; i--){
		for(int j = 0; j < 79; j++){
 			if(board[i][j] != ' '){
				if(i == 29){
					printf("Game Over"); //ends game if the word is on the bottom line
					exit(0);
				}
				else{
					board[i+1][j] = board[i][j]; //moves the word down
					board[i][j] = ' ';  //resets the words previous spot to empty
				}
			}
		}
	}
}

void generateWord(FILE *fileName, char* randomWords){
    char thrownLine[50]; //Stores the previous lines so that they do not get put onto the board
    int randomLine = 0;
    randomLine = (rand() % 1000) + 1; //Generates which line the word will be at in the file
    //The loop puts the values of the preceding lines into the thrownLine so it does not mix with the actual value
    for(int i = 1; i < randomLine; i++){
        fgets(thrownLine, randomLine, fileName);
    }
    fgets(randomWords, randomLine, fileName);
}

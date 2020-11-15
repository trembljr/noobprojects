/*
Cole Eichacker - 20% (board design)
Jordan Amberg - 40% added appending to text file, DeleteWords function, PrintBoard function, started MoveWords function
Joseph Trembley - 40% completed generateWord function, various bug fixing/testing, added timer to both add more words and print final time, comments
Sami Bensellam - 0%
Samuel Kidane - 0%
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void PrintBoard(char board[30][80]);
void UpdateBoard(char words[],char board[30][80], struct timeval startTime, struct timeval endTime);
void MoveWords(char board[30][80], struct timeval start, struct timeval end);
void generateWord(FILE *fileName, char* randomWords, int *w);
void deleteWords(char userEntry[], char board[][80]);

int main(){
	char playOrAdd;
	char userAddWord[10];
	char board[30][80];
	char tempWordVar[50];
	char userWord[30];
	struct timeval start, end, gameStart, gameEnd;
	int d = 0;
	int timeBetween = 1;
	int gameTime = 0;
	for(int w = 0; w < 30; w++){
		for(int i = 0; i < 80; i++){
			board[w][i] = ' ';
		}
	}
	FILE *fp;
	printf("Hello, this is a typing game. You will need to type the words as they" 
	"appear.\nWould you like to play or add a word?\n(Type ‘p’ for play or ‘a’ to add words)");
    scanf(" %c", &playOrAdd);
    srand(time(NULL));
	while(playOrAdd == 'a'){
        FILE *fp = fopen("wordList.txt", "a+");
        printf("Type a word that you want to add(one word, no spaces)\n");
		scanf(" %s",userAddWord);
		fprintf(fp, "\n");
		fprintf(fp, "%s", userAddWord);  //appends word to end of file
		printf("Your word has been added.\n Would you like to add another word? (Type "
        "'p' or 'a')\n");
		scanf(" %c", &playOrAdd);
		fclose(fp);
	}
	gettimeofday(&gameStart, NULL);
	while(playOrAdd == 'p'){
	    gettimeofday(&start, NULL);
	    for(int i = 0; i < timeBetween; i++){ //Updates the board for the number of seconds between last user input and current input
	        generateWord(fp, &tempWordVar, &d); //Generates a word to go on the board
		    UpdateBoard(tempWordVar, board, gameStart, gameEnd); //Puts the word onto the board once generated
	    }
	    PrintBoard(board);
		scanf("%s", &userWord);
		deleteWords(userWord,board); //Compares user input to every word on the board and deletes the appropriate word
		gettimeofday(&end, NULL);
        timeBetween = fabs((end.tv_sec - start.tv_sec)); //Finds the number of seconds between last input and current input
	}
}

void PrintBoard(char board[30][80]){ //Prints out the board with the borders and words in appropriate places
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

void UpdateBoard(char words[],char board[30][80], struct timeval startTime, struct timeval endTime){
	int length = 0;
	int i = 0;
	while(words[i] != '\0'){ //Gets the appropriate length for the word
	    length++;
	    i++;
	}
	int temp = rand() % (77 - length) +1; //generates starting position of the word (x value)
	MoveWords(board, startTime, endTime);
	for(int i = 0; i < length - 2; i++){ //replaces the spaces with the characters of the word
		board[0][temp+i] = words[i];
	}
}

void MoveWords(char board[30][80], struct timeval start, struct timeval end){
	for(int i = 29; i >= 0; i--){
		for(int j = 0; j < 79; j++){
 			if(board[i][j] != ' '){
				if(i == 29){
					gettimeofday(&end, NULL);
					printf("Game Over. "); //ends game if the word is on the bottom line
					int userTime = fabs((end.tv_sec - start.tv_sec)); //Finds the total user time in seconds
					printf("Your time was %d seconds.\n", userTime); //Prints the time the user took to end the game
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

void generateWord(FILE *fileName, char* randomWords, int *w){
    char thrownLine[50]; //Stores the previous lines so that they do not get put onto the board
    int randomLine = 0;
    int usedWords[1000];
    randomLine = (rand() % 999) + 1; //Generates which line the word will be at in the file
    fileName = fopen("wordList.txt", "r");
    for(int j = 0; j < 1000; j++){
        if(usedWords[j] == randomLine){
            randomLine = (rand() % 999) + 1; //Generates a new line when it has already been used in the function
        }
    }
    //The loop puts the values of the preceding lines into the thrownLine so it does not mix with the actual value
    for(int i = 1; i < randomLine; i++){
        fgets(thrownLine, randomLine, fileName);
    }
    usedWords[*w] = randomLine;
    w++;
    fgets(randomWords, randomLine, fileName); //Gets the value at the actual line to out into the function
    fclose(fileName);
}

void deleteWords(char userEntry[], char board[30][80]){
	char fullWord[20];
	for(int i = 29; i >= 0; i--){
		for(int j = 1; j < 79; j++){
 			if(board[i][j] == userEntry[0] && (board[i][j-1] == ' ' || board[i][j-1] == '|') ){ //Finds the first character of a word
				fullWord[strlen(userEntry)] = '\0'; //finds the proper size of fullWord
				for(int w = 0; userEntry[w] == board[i][w+j]; w++){ //Puts the letters from the board into a string
					fullWord[w] = board[i][j+w];
				}
				int y = strlen(fullWord);
				if(strcmp(userEntry,fullWord) == 0 && board[i][j+y] == ' '){ //Tests to see if the word the user inputs is on the board, compares the two words
					for(int w = 0; userEntry[w] == board[i][w+j]; w++){
						board[i][j+w] = ' '; //Replaces the matching letters on the board with spaces
					}
					return; //Ends the function after finding a match
				}
			}
		}
	}
}

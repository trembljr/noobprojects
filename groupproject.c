//program starts here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
TEAM PERCENTAGES
----------------------------------------------------
Jordan Amberg - 20% - wrote quiz1(programmed and wrote questions) and various bug fixes
----------------------------------------------------
Sami Bensellam - 20% - wrote questions, created some code, minor edits, bug fixes
----------------------------------------------------
Cole Eichacker - 20% - wrote questions, verified code, fixed bugs and finished code segments
----------------------------------------------------
Joseph Trembley - 20% - programmed quiz 3, testing
----------------------------------------------------
Samuel Kidane - 20%
*/



int main(){
	//Declaring variables for user input
	char userTrueFalse;
	char userMultChoice;
	char userBlank[50];
	char newQuiz = 'Y';
    while(toupper(newQuiz) == 'Y'){
        //Declares and reassigns variables used each loop
        double score = 0;
    	double scoreAvg = 0;
    	double numScores = 0;
    	newQuiz = 'A';
        //Makes sure the number for the random generation is valid
    	int luckyNum = 0;
    	while(luckyNum < 1 || luckyNum > 9) {
    		printf("Please enter a number between 1 and 9.\n");
    		scanf(" %d", &luckyNum);
    	}
    	
    	srand(luckyNum * 67);
    	int quizNum = (rand() % 3) + 1;
    	printf("You are taking quiz number %d.\n", quizNum);
        
        if (quizNum == 1){
            while(score != 15){
			score = 0;
    		printf("True or false: This is an infinite loop\nwhile(1){\n   printf(\"1\");\n}\n");
    		printf("A. True\nB. False\n"); //correct answer: A
    		scanf(" %c", &userTrueFalse);
    		if(toupper(userTrueFalse) == 'A'){
    			printf("Correct Answer\n");
    			score += 5;
    		}
    		else{
    			printf("Wrong Answer\n");
    		}
    		printf("What size array will the compiler create for the following string?:\n   char str[] = “midterm”\n");
    		printf("A. 7\nB. 8\nC. 30\nD. does not compile\n");
    		scanf(" %c", &userMultChoice);
    		if(toupper(userMultChoice) == 'B'){
    			printf("Correct Answer\n");
    			score += 5;
    		}
    		else 
    			printf("Wrong Answer\n");
    		printf("Fill in the blank: what will the following code output on the final iteration?\nfor(int i = 1; i <= 10; i += 2){\n   printf(“%%d“, i+1);\n}\n");
    		scanf(" %s", &userBlank);
    		if (strcmp(userBlank, "10") == 0){
    			printf("Correct Answer\n");
    			score += 5;
    		}
    		else 
    			printf("Wrong Answer\n");
    		if(score == 15)
    			printf("Congratulations! You passed! Your score was 15!\n");
    		else
    			printf("You failed, retake the quiz. Your score was %lf out of 15\n",score);
    	
            scoreAvg += score;
    	    numScores++;    
        }
    }
    
    	if(quizNum == 2){
    	   while(score != 15){
            score = 0;
        	//question 1 of quiz 2
    		printf("True or False: Only character or integer can be used in switch statement?\n");
    		printf("A:True\nB:False\n");
    		scanf(" %c" , &userTrueFalse);
    		if(toupper(userTrueFalse) == 'A'){
    		    printf("Correct Answer\n");
    		    score += 5;
    		}else{
    			printf("Wrong Answer\n");
    		}
    		//question 2 of quiz 2
    		printf("To print a double value which format specifier can be used?\n");
    		printf("A: %%l \nB:%%lf \nC:%%d \nD: none of the above\n");
    		scanf(" %c" , &userMultChoice);
    	    if(toupper(userMultChoice) == 'B'){
    	        printf("Correct Answer\n");
    	        score += 5; 
    	    }else {
    		    printf("Wrong Answer\n");
            }
        	// question 3 of quiz 2
        	printf("What number do you replace the ? with to assign y to the first index of array myQ[]?\nint myQ[5];\nint x = myQ[?];\n");
        	scanf("%s", userBlank);
        	if(strcmp(userBlank, "0") == 0){
        		printf("Correct Answer\n");
        	    score += 5; 
            }else{
        	    printf("Wrong, you answered %s\n", userBlank);
            }
        	
        	if(score == 15){
        		printf("Congratulations! Quiz passed! You got 15 out of 15!\n");
        			
        	   }
        	else{
        		printf("Quiz not passed, please retake. Your score was %lf out of 15\n",score);
        	}
        	scoreAvg += score;
    	    numScores++;
        }
    }
    	if(quizNum == 3){
    	while(score != 15){
            score = 0;
            //Question 1 of Test 3
            printf("True or False: <stdio.h> lets you do math functions (ex: pow)\n");
            printf("A. True\nB. False\n");
            scanf(" %c", &userTrueFalse);
            if(toupper(userTrueFalse) == 'B') {
    	        printf("Correct Answer\n");
    	        score+= 5;
            }else{
    	        printf("Incorrect Answer\n");
            }
    
            //Question 2 of Test 3
            printf("What variable type does not require an & in the scanf function?\n");
            printf("A. int\nB. double\nC. string\nD.char\n");
            scanf(" %c", &userMultChoice);
            if(toupper(userMultChoice) == 'C') {
            	printf("Correct Answer\n");
            	score+= 5;
            }else{
            	printf("Incorrec Answert\n");
            }
    
            //Question 3 of Test 3
            printf("Prototypes are declared _____ the main function.(answer in lowercase)\n");
            scanf(" %s", userBlank);
            if(strcmp(userBlank, "before") == 0) {
            	printf("Correct Answer\n");
            	score+= 5;
            }else{
            	printf("Incorrect Answer\n");
            }
            	if(score == 15){
            		printf("Congratulations! Quiz passed! You got 15 out of 15 on the quiz!\n");
            			
            	   }
            	else{
            		printf("Quiz not passed, please retake. Your score was %lf out of 15\n",score);
            	}
            scoreAvg += score;
    	    numScores++;
            }
    	}
    	scoreAvg = scoreAvg / numScores;
    	printf("Your average score on this quiz was %lf.\n", scoreAvg);
		newQuiz = 'A';
		while(toupper(newQuiz) != 'Y'){
    		printf("Would you like to try a new quiz?\n");
    		scanf(" %c", &newQuiz);
    		if(toupper(newQuiz) == 'N'){
    		    break;
    		}
        }
    }
}

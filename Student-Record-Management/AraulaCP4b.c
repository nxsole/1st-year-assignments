/*	Name: Angel Fredelle Mishka A. Araula
	Date Started: April 7, 2024
	Date Finished: April 10, 2024
	Summary: This program is designed to manage student records for a class.
	It allows the user to input student IDs and their quiz scores, calculates 
	the highest, lowest, and average scores for each student, and then displays 
	the records in a tabular format. The program also includes error handling for 
	invalid inputs such as out-of-range scores and duplicate student IDs.*/
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
//constants
#define ROWS 10
#define COLS 9
//functions
int InputStudID(int student[ROWS][COLS], int *numStudents);
int Calculate(int student[ROWS][COLS], int numStudents, int *highest, int *lowest);
void Display(int student[ROWS][COLS], int numStudents, int highest, int lowest);

//main function
void main(void) {
int student[ROWS][COLS], highest, lowest, average;
int numStudents = 0;
char choice;

    do {
    	system("cls");
        InputStudID(student, &numStudents);
        Calculate(student, numStudents, &highest, &lowest);
        Display(student, numStudents, highest, lowest);
        
        do {
        printf("\nDo you want to input records for another student? (Y/N): ");
        scanf(" %c", &choice);
        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        	printf("\nError. Please enter 'Y' or 'N'.");	
			}
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    } while (choice == 'Y' || choice == 'y');
    
    printf("\nExiting the program. . .");
}
//input student ID
int InputStudID(int student[ROWS][COLS], int *numStudents) {
	int numRead = 0, studExists;
	//input ID
	do {
		system("cls");
	printf("---ADD A STUDENT---\n");
	if (*numStudents >= ROWS) {
        printf("Maximum number of students reached.\n");
        printf("\nExiting the program. . .");
        break;
    }
        printf("Enter student ID for student %d: ", *numStudents + 1);
        numRead = scanf("%d", &student[*numStudents][0]);
        
        if (numRead != 1 || student[*numStudents][0] < 1000 || student[*numStudents][0] > 9999) {
        printf("Error. Please enter a number from 1000 to 9999.\n");
        getchar();
        //system("pause");  idk if pwede ba ni gamiton maam rivera...
        printf("\nPress any key to continue...");
        getch();
        }
    // Check if ID number already in use
        studExists = 0;
        for (int i = 0; i < *numStudents; i++) {
            if (student[i][0] == student[*numStudents][0]) {
                studExists = 1;
                break;
            }
        }
		if (*numStudents > ROWS) {
        printf("Maximum number of students reached.\n");
        printf("\nExiting the program. . .");
    	}
    	if (studExists) {
            printf("Error. Student number %d already exists. Please enter a different ID number.\n",student[*numStudents][0]); 
            getchar();
            //system("pause");
			printf("\nPress any key to continue...");
        	getch(); 
        }
    
	}  while (numRead != 1 || student[*numStudents][0] < 1000 || student[*numStudents][0] > 9999 || studExists || *numStudents > ROWS);
	//input quiz
    printf("Enter quiz scores for student %d: \n", *numStudents + 1);
	for (int j = 1; j <= 5; j++) {
    do {
        printf("Quiz %d: ", j);
        scanf("%d", &student[*numStudents][j]);
        if (student[*numStudents][j] < 0 || student[*numStudents][j] > 100) {
            printf("Error. Score not in range, Please enter another score from 1-100.\n");
        }
    } while (student[*numStudents][j] < 0 || student[*numStudents][j] > 100);
}

    (*numStudents)++;
    return *numStudents;
}
//calculate function
int Calculate(int student[ROWS][COLS], int numStudents, int *highest, int *lowest) {

    for (int i = 0; i < numStudents; i++) {
    	*highest = student[i][1];
        *lowest = student[i][1];
        int sum = 0;
        for (int j = 1; j <= 5; j++) {
            sum += student[i][j];

            if (student[i][j] > *highest) {
                *highest = student[i][j];
            }

            if (student[i][j] < *lowest) {
                *lowest = student[i][j];
            }
        }
        student[i][6] = *highest;
        student[i][7] = *lowest;
        student[i][8] = sum / 5; //average
    }
}
//display function
void Display(int student[ROWS][COLS], int numStudents, int highest, int lowest) {
	
	system("cls");
 printf("---STUDENT RECORD---\n");
    printf("ID\tQuiz1\tQuiz2\tQuiz3\tQuiz4\tQuiz5\tHighest\tLowest\tAverage\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t", student[i][0]); //student ID
        for (int j = 1; j <= 5; j++) {
            printf("%d\t", student[i][j]); //quizzes
        }
        printf("%d\t%d\t%d\n", student[i][6], student[i][7], student[i][8]); //high low average
    }
}
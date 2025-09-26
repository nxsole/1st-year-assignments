/*	Name: Angel Fredelle Mishka A. Araula
	Date Started: March 12, 2023
	Date Finished: March 23, 2023
	Summary: a modular program simulating a book record maintenance.
	 it can add, search, edit, delete, filter out(available books, book type,
	 and author), and display books.*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//constants
#define SIZE 3
#define MAXSIZE 5
#define TITLESIZE 100
#define AUTHORSIZE 50
#define TYPESIZE 15
//structure
typedef struct bookrecord
{
	int bookBookNum;
	char bookTitle[TITLESIZE];
	char bookAuthor[AUTHORSIZE];
	int bookYear;
	char bookType[TYPESIZE];
	float bookCost;
	char bookAvail;
} bookrec;
//functions 
int MainMenu();
int DataEntry(bookrec book[SIZE], int count);
void SearchandEdit(bookrec book[SIZE], int count, int found);
void SearchandDelete(bookrec book[SIZE], int *count, int found);
void FilterOut(bookrec book[SIZE], int count, int found);
void Display(bookrec book[SIZE], int count);
void gotoxy(short x, short y);
void sortArray(bookrec book[SIZE], int count);
//main function
int main(void) {
    int Choice, count = 0, found = 0, deleteRec;
    bookrec book[SIZE];
    char ch;
    
    do {
        system("cls");
        Choice = MainMenu(book);
        
        switch (Choice) {
            case 1:
                count = DataEntry(book, count);
                break;
            case 2:
            	SearchandEdit(book, count, found);
            	break;
            case 3:
            	SearchandDelete(book, &count, found);
            	break;
            case 4:
            	FilterOut(book, count, found);
            	break;
            case 5:
            	Display(book, count);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
		do {
			printf("\nGo back to Main Menu? (Y/N): ");
        scanf(" %c", &ch);
        if (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') {
        	printf("\nError. Please enter 'Y' or 'N'.");	
			}
		} while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
    } while (ch == 'Y' || ch == 'y');

    printf("Exiting the program...\n");
    return 0;
}
//mainmenu bar
int MainMenu(void) {
    int count = 0, choice, numRead;
    
    do {
        system("cls");
        printf("----BOOK RECORD----\n");
        printf("[1]Add a Book Record.\n[2]Search and Edit a Record.\n[3]Search and Delete a Record.\n[4]Filter out Books.\n[5]Display all Records.\n[6]Exit.\n");
        printf("\nInput Choice: ");
        numRead = scanf("%d", &choice);
        
        if (numRead == 1) {
            return choice;
        }
        else {
            printf("Error. Please input a number.\n");
            getchar();
            printf("\nPress any key to continue.");
            getch();
        }
    } while (numRead != 1);
}
//add a book record
int DataEntry(bookrec book[SIZE], int count) {
    int BN=1, year=1, numRead=0, bookExists, typeChoice;
    float cost=1;
    char title[TITLESIZE], author[AUTHORSIZE], type[TYPESIZE], avail;
    char confirm;
    
    system("cls");
    if (count >= SIZE) {
        printf("Error: Book record is full. Cannot add more books.\n");
        return count;
    }
    else {
    printf("---ADD A BOOK RECORD---\n");
    fflush(stdin);
   do {
        printf("\nBOOK NUMBER (10000-99999): ");
        numRead = scanf("%d", &BN);
        if (numRead != 1 || BN < 10000 || BN > 99999) {
            printf("Error. Please enter a number from 10000 to 99999.\n");
            getchar();
        }
        // Check if book number already in use
        bookExists = 0;
        for (int i = 0; i < count; i++) {
            if (book[i].bookBookNum == BN) {
                bookExists = 1;
                break;
            }
        }
        if (bookExists) {
            printf("Error. Book number %d already exists. Please enter a different book number.\n", BN);
        }
        } while (numRead != 1 || BN < 10000 || BN > 99999 || bookExists);
        getchar();
    
    printf("BOOK TITLE: ");
    fgets(title, TITLESIZE, stdin);
    title[strlen(title) - 1] = '\0';

    printf("BOOK AUTHOR: ");
    fgets(author, AUTHORSIZE, stdin);
    author[strlen(author) - 1] = '\0';

    do {
        printf("YEAR OF PUBLICATION (1900-2021): ");
        numRead = scanf("%d", &year);
        if (numRead != 1 || year < 1900 || year > 2021) {
            printf("Error. Year out of range, please enter a year from 1900 to 2021.\n");
            getchar();
        }
    } while (numRead != 1 || year < 1900 || year > 2021);
    getchar();
    
     do {
        printf("BOOK TYPE:\n");
        printf("[1] Hardbound\n");
        printf("[2] Paperback\n");
        printf("[3] Springbound\n");
        printf("Enter Choice: ");
        numRead = scanf("%d", &typeChoice);
        if (numRead != 1) {
    	printf("Error. Please enter a number from 1-3.\n");
        getchar();
		}

        switch (typeChoice) {
            case 1:
                strcpy(type, "Hardbound");
                break;
            case 2:
                strcpy(type, "Paperback");
                break;
            case 3:
                strcpy(type, "Springbound");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (numRead != 1 || typeChoice != 1 && typeChoice != 2 && typeChoice != 3);

    printf("Selected Book Type: %s\n", type);

	do {
	printf("BOOK COST: ");
    numRead = scanf("%f", &cost);
    if (numRead != 1 || cost < 0) {
    	printf("Error. Please enter a valid non-negative cost.\n");
        getchar();
		}
	} while (numRead != 1 || cost < 0);
	getchar();
	
    do {
        printf("BOOK AVAILABILITY ('Y' or 'N'): ");
        scanf(" %c", &avail);
        if (avail != 'Y' && avail != 'y' && avail != 'N' && avail != 'n') {
            printf("Error. Please enter 'Y' or 'N'.\n");
        }
    } while (avail != 'Y' && avail != 'y' && avail != 'N' && avail != 'n');

	do {
	printf("\nConfirm adding this record? (Y/N): ");
    scanf(" %c", &confirm);
    
    if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
    	printf("Error. Please enter 'Y' or 'N'.\n");
	}
	} while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
    if (confirm == 'Y' || confirm == 'y') {
        // Store data 
        book[count].bookBookNum = BN;
        strcpy(book[count].bookTitle, title);
        strcpy(book[count].bookAuthor, author);
        book[count].bookYear = year;
        strcpy(book[count].bookType, type);
        book[count].bookCost = cost;
        book[count].bookAvail = (avail == 'Y' || avail == 'y') ? 'Y' : 'N';
        count++;
        system("cls");
		printf("Succesfully added to record.\n");
	}
	else {
	system("cls");
	printf("Adding book to record was unsuccessful.\n");	
	} 
    return count;
}
}
//search and edit book
void SearchandEdit(bookrec book[MAXSIZE], int count, int found) {
    int i, j, numRecord = 0, typeChoice, numRead=0;
    char result, confirm, type[TYPESIZE], lowercaseTitle[TITLESIZE], lowercaseAuthor[AUTHORSIZE];
    float cost;
    char BOOK[TITLESIZE];

    do {
        system("cls");
        printf("---SEARCH AND EDIT A BOOK---\n");
        fflush(stdin);
        printf("Enter Book Title/Author to Search: ");
        fgets(BOOK, TITLESIZE, stdin);
        BOOK[strlen(BOOK) - 1] = '\0';
        // Convert lowercase
        for (i = 0; BOOK[i]; i++) {
            BOOK[i] = tolower(BOOK[i]);
        }
        for (i = 0; i < count; i++) {
        	 strcpy(lowercaseTitle, book[i].bookTitle); 
        strcpy(lowercaseAuthor, book[i].bookAuthor);
        for (j = 0; lowercaseTitle[j]; j++) {
            lowercaseTitle[j] = tolower(lowercaseTitle[j]);
        }
        for (j = 0; lowercaseAuthor[j]; j++) {
    		lowercaseAuthor[j] = tolower(lowercaseAuthor[j]);
		}
            if (strcmp(lowercaseTitle, BOOK) == 0 || strcmp(lowercaseAuthor, BOOK) == 0) {
                sortArray(book, count);
                printf("BOOK NUMBER: %d\n", book[i].bookBookNum);
                printf("TITLE: %s\n", book[i].bookTitle);
                printf("AUTHOR: %s\n", book[i].bookAuthor);
                printf("YEAR: %d\n", book[i].bookYear);
                printf("TYPE: %s\n", book[i].bookType);
                printf("COST: %.2f\n", book[i].bookCost);
                printf("AVAILABILITY: %c\n\n", book[i].bookAvail);
                found = 1;
                numRecord++;
            }
        }

        if (numRecord == 0) {
            printf("No books found with the given keyword.\n");
            return;
        }

        if (numRecord > 1 && strcmp(lowercaseAuthor, BOOK) == 0) {
            printf("Multiple books found with the given author. Please input the title instead: ");
            puts("\nPress any key to continue.");
            getch();
        }
    } while (numRecord > 1 && strcmp(lowercaseAuthor, BOOK) == 0);

    printf("\nDo you want to continue editing? (Y/N): ");
    scanf(" %c", &result);
    if (result == 'Y' || result == 'y') {
        found = 0;
        system("cls");
        //lowercase
        for (i = 0; i < count; i++) {
        strcpy(lowercaseTitle, book[i].bookTitle); 
        strcpy(lowercaseAuthor, book[i].bookAuthor);
        for (j = 0; lowercaseTitle[j]; j++) {
            lowercaseTitle[j] = tolower(lowercaseTitle[j]);
        }
        for (j = 0; lowercaseAuthor[j]; j++) {
    		lowercaseAuthor[j] = tolower(lowercaseAuthor[j]);
		}
            if (strcmp(lowercaseTitle, BOOK) == 0 || strcmp(lowercaseAuthor, BOOK) == 0) {
        do {
        printf("ENTER NEW BOOK TYPE:\n");
        printf("[1] Hardbound\n");
        printf("[2] Paperback\n");
        printf("[3] Springbound\n");
        printf("Enter Choice: ");
        numRead = scanf("%d", &typeChoice);
        if (numRead != 1) {
    	printf("Error. Please enter a number from 1-3.\n");
        getchar();
		}
        switch (typeChoice) {
            case 1:
                strcpy(type, "Hardbound");
                break;
            case 2:
                strcpy(type, "Paperback");
                break;
            case 3:
                strcpy(type, "Springbound");
                break;
            default:
            	system("cls");
                printf("Invalid choice. Please try again.\n");
                break;
      		  }
   		 } while (numRead != 1 || typeChoice != 1 && typeChoice != 2 && typeChoice != 3);

    printf("Selected Book Type: %s\n", type);

	do {
	printf("ENTER NEW BOOK COST: ");
    numRead = scanf("%f", &cost);
    if (numRead != 1 || cost < 0) {
    	printf("Error. Please enter a valid non-negative cost.\n");
        getchar();
		}
	} while (numRead != 1 || cost < 0);
	getchar();

                printf("\nConfirm editing this record? (Y/N): ");
                scanf(" %c", &confirm);

                if (confirm == 'Y' || confirm == 'y') {
                    strcpy(book[i].bookType, type);
                    book[i].bookCost = cost;
                    found = 1;
                    system("cls");
                    printf("Record edited successfully.\n");
                    break;
                }
                else {
                	system("cls");
                    printf("Editing book was unsuccessful.\n");
				}
            }
        }
    } 
	else {
        system("cls");
        printf("Editing book was unsuccessful.\n");
    }
}
//search and delete book
void SearchandDelete(bookrec book[MAXSIZE], int *count, int found) {
    int i, j, numRecord = 0, foundIndex = -1; 
    char confirm, lowercaseTitle[TITLESIZE], lowercaseAuthor[AUTHORSIZE];
    char BOOK[TITLESIZE];

    do {
        system("cls");
        printf("---SEARCH AND DELETE A BOOK---\n");
        printf("Enter Book Title/Author to Search: ");
        fflush(stdin);
        fgets(BOOK, TITLESIZE, stdin);
        BOOK[strlen(BOOK) - 1] = '\0';
        
        // Convert to lowercase
        for (i = 0; BOOK[i]; i++) {
            BOOK[i] = tolower(BOOK[i]);
        }

        for (i = 0; i < *count; i++) {
            strcpy(lowercaseTitle, book[i].bookTitle);
            strcpy(lowercaseAuthor, book[i].bookAuthor);

            for (j = 0; lowercaseTitle[j]; j++) {
                lowercaseTitle[j] = tolower(lowercaseTitle[j]);
            }
            for (j = 0; lowercaseAuthor[j]; j++) {
                lowercaseAuthor[j] = tolower(lowercaseAuthor[j]);
            }

            if (strcmp(lowercaseTitle, BOOK) == 0 || strcmp(lowercaseAuthor, BOOK) == 0) {
                sortArray(book, *count);
                printf("BOOK NUMBER: %d\n", book[i].bookBookNum);
                printf("TITLE: %s\n", book[i].bookTitle);
                printf("AUTHOR: %s\n", book[i].bookAuthor);
                printf("YEAR: %d\n", book[i].bookYear);
                printf("TYPE: %s\n", book[i].bookType);
                printf("COST: %.2f\n", book[i].bookCost);
                printf("AVAILABILITY: %c\n\n", book[i].bookAvail);
                found = 1;
                numRecord++;
                foundIndex = i;
            }
        }

        if (numRecord == 0) {
            printf("No books found with the given keyword.\n");
            return;
        }

        if (numRecord > 1 && strcmp(lowercaseTitle, BOOK) != 0 && strcmp(lowercaseAuthor, BOOK) == 0)  {
            printf("Multiple books found with the given author. Please input the title instead.");
            printf("\nPress any key to continue.");
            getch();
        }
     } while (numRecord > 1 && strcmp(lowercaseAuthor, BOOK) == 0);

    printf("\nDo you want to delete this book? (Y/N): ");
    scanf(" %c", &confirm);
    if (confirm == 'Y' || confirm == 'y') {
        // Delete book
        for (j = foundIndex; j < *count - 1; j++) {
            book[j] = book[j + 1];
        }
        (*count)--;
        system("cls");
        printf("Book deleted successfully.\n");
    } else {
        system("cls");
        printf("Book deletion was unsuccessful.\n");
    }
}
//filter out books
void FilterOut(bookrec book[SIZE], int count, int found) {
    int i, j, choice, typeChoice, numRead = 0;
    char author[AUTHORSIZE], lowercaseAuthor[AUTHORSIZE], type[TYPESIZE];
    bookrec authorBooks[SIZE], availBooks[SIZE], typeBooks[SIZE];
    int authorCount = 0, availCount=0, typeCount=0;
    
	system("cls");
	do {
    printf("---FILTER OUT BOOKS---\n");
    fflush(stdin);
    printf("[1]Books Available\n");
    printf("[2]Book Type\n");
    printf("[3]Book Author\n\n");
    printf("Enter an option: ");
    numRead = scanf("%d", &choice);
	if (numRead != 1) {
    	printf("Error. Please enter a number from 1-3.\n");
        getchar();
        system("cls");
		}
		
    switch (choice) {
        case 1:
            for (i = 0; i < count; i++) {
                if (book[i].bookAvail == 'Y') {
                    availBooks[availCount++] = book[i];
                }
            }
            if (availCount > 0) {
                Display(availBooks, availCount);
            } else {
            	system("cls");
                printf("No available books.\n");
            }
            break;
        case 2:
        	system("cls");
            do {
        printf("BOOK TYPE:\n");
        printf("[1] Hardbound\n");
        printf("[2] Paperback\n");
        printf("[3] Springbound\n");
        printf("Enter Choice: ");
        numRead = scanf("%d", &typeChoice);
        if (numRead != 1) {
        system("cls");
    	printf("Error. Please enter a number from 1-3.\n");
        getchar();
		}
		
        	switch (typeChoice) {
            	case 1:
                	strcpy(type, "Hardbound");
                	for (i = 0; i < count; i++) {
                        if (strcmp(book[i].bookType, "Hardbound") == 0) {
                            typeBooks[typeCount++] = book[i];
                        }
                    }
                    if (typeCount > 0) {
                        Display(typeBooks, typeCount);
                    } else {
                    	system("cls");
                        printf("No Hardbound books.\n");
                    }
                	break;
            	case 2:
                	strcpy(type, "Paperback");
                	for (i = 0; i < count; i++) {
                        if (strcmp(book[i].bookType, "Paperback") == 0) {
                            typeBooks[typeCount++] = book[i];
                        }
                    }
                    if (typeCount > 0) {
                        Display(typeBooks, typeCount);
                    } else {
                    	system("cls");
                        printf("No Paperback books.\n");
                    }
                	break;
            	case 3:
                	strcpy(type, "Springbound");
                	for (i = 0; i < count; i++) {
                        if (strcmp(book[i].bookType, "Springbound") == 0) {
                            typeBooks[typeCount++] = book[i];
                        }
                    }
                    if (typeCount > 0) {
                        Display(typeBooks, typeCount);
                    } else {
                    	system("cls");
                        printf("No Springbound books.\n");
                    }
                	break;
                default:
                	system("cls");
                	printf("Invalid choice. PLease try again.\n");
                	break;
        }
    } while (numRead != 1 || typeChoice != 1 && typeChoice != 2 && typeChoice != 3);
            break;
        case 3:
            system("cls");
            fflush(stdin);
            printf("ENTER BOOK AUTHOR TO FILTER: ");
            fgets(author, AUTHORSIZE, stdin);
            author[strlen(author) - 1] = '\0';
            
            for (i = 0; author[i]; i++) {
                author[i] = tolower(author[i]);
            }
            found = 0;
            for (i = 0; i < count; i++) {
                strcpy(lowercaseAuthor, book[i].bookAuthor);
                for (j = 0; lowercaseAuthor[j]; j++) {
                    lowercaseAuthor[j] = tolower(lowercaseAuthor[j]);
                }
                if (strcmp(lowercaseAuthor, author) == 0) {
                    authorBooks[authorCount++] = book[i]; 
                    found = 1;
                }
            }

            if (found) {
                Display(authorBooks, authorCount);
            }
            if (!found) {
            	system("cls");
                printf("No books found with the given author.\n");
            }
			if (count == 0) {
				system("cls");
    	    puts("Sorry. There are no book records to display.");
    		}
            break;
        default:
        	system("cls");
            printf("Invalid choice. PLease try again.\n");
            break;
	    }
	} while (numRead != 1 || choice != 1 && choice != 2 && choice != 3);
}

//Display Books
void Display(bookrec book[SIZE], int count) {
    int i, x, y;
    system("cls");
    x = 1;
    y = 4;
        if (count == 0) {
        puts("Sorry. There are no book records to display.");
    }
    else {
    	sortArray(book, count);
        printf("---BOOK RECORDS---");
        gotoxy(x,2); printf("BOOK NUMBER");
        gotoxy(x+15,2); printf("BOOK TITLE");
        gotoxy(x+35,2); printf("BOOK AUTHOR");
        gotoxy(x+55,2); printf("YEAR");
        gotoxy(x+65,2); printf("BOOK TYPE");
        gotoxy(x+85,2); printf("BOOK COST");
        gotoxy(x+100,2); printf("BOOK AVAILABILITY");

        for(i=0;i<count;i++) {
            gotoxy(x,y); printf("%d", book[i].bookBookNum);
            gotoxy(x+15,y); printf("%s", book[i].bookTitle);
            gotoxy(x+35,y); printf("%s", book[i].bookAuthor);
            gotoxy(x+55,y); printf("%d", book[i].bookYear);
            gotoxy(x+65,y); printf("%s", book[i].bookType);
            gotoxy(x+85,y); printf("%.2f", book[i].bookCost);
            gotoxy(x+100,y); printf("%c", book[i].bookAvail);
            y++;
        }
    }
    puts("\nPress any key to continue.");
    getch();
    system("cls");
}
//define gotoxy
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//sort in ascending order
void sortArray(bookrec book[SIZE], int count) {
	int i, j;
	bookrec sort;
		
        for (i = 0; i < count - 1; i++) {
            for (j = 0; j < count - i - 1; j++) {
                if (book[j].bookBookNum > book[j + 1].bookBookNum) {
                    sort = book[j];
                    book[j] = book[j + 1];
                    book[j + 1] = sort;
                }
            }
        }
}
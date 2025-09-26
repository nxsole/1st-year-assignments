/*	Name: Angel Fredelle Mishka A. Araula
	course and section: BSIT - CCS3B
	Date Started: May 21, 2024
	Date Finished: , 2024
	Summary: a modular program simulating a book and borrower record maintenance
	using singly linked list. Conversion of array of structures to singly linked list.
	 It can add, search, edit, delete, filter out display(available books, book type,
	 and author), and for the borrowers, it can add, search, edit, delete, and display
	 borrowers.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
//constants
#define TITLESIZE 50
#define AUTHORSIZE 50
#define TYPESIZE 15
#define NAMESIZE 50
//book structure
typedef struct bookrecord {
	int bookBookNum; 
	char bookTitle[TITLESIZE];
	char bookAuthor[AUTHORSIZE];
	int bookYear;
	char bookType[TYPESIZE];
	float bookCost;
	char bookAvail;
} BOOKREC;
//functions
void Create(FILE *fp);
int BookMenu(FILE *fp, BOOKREC book);
//book functions
int DataEntry(FILE *fp, BOOKREC book);
void SearchandEdit(FILE *fp, BOOKREC book);
void SearchandDelete(FILE *fp, BOOKREC book);
void DisplayBooks (FILE *fp, BOOKREC book);
void DisplayAvail(FILE *fp, BOOKREC book);
void DisplayType(FILE *fp, BOOKREC book);
void DisplayAuthor(FILE *fp, BOOKREC book);
void DisplayAll(FILE *fp, BOOKREC book);
void PrintDisplay(FILE *fp, BOOKREC book, int y);
void PrintDisplayTitle(void);
//main
int main(void) {
	FILE *fp = NULL;
	BOOKREC book;
    
    int choice, numRead;
    char mainMenuChoice;

	Create(fp);
    do {
        system("cls");
        printf("----MAIN MENU----\n");
        printf("[1] Maintenance of Book Records.\n[2] Maintenance of Borrower Records.\n[3] Exit this Program.\n");
        printf("\nInput Choice: ");
        numRead = scanf("%d", &choice);

        if (numRead == 1) {
            switch (choice) {
                case 1:
                    BookMenu(fp, book);
                    break;
                case 2:
                    //BorrMenu(&borrHead);
                    break;
                case 3:
                    printf("Exiting the program...\n");
                    return 0;
                default:
                    printf("Invalid choice. Please input a number from 1-3.\n");
                    break;
            }
        } 
		else {
            printf("Invalid choice. Please input a number 1-3.\n");
            fflush(stdin);
        }

        do {
            printf("\nGo back to Main Menu? (Y/N): ");
            scanf(" %c", &mainMenuChoice);
            if (mainMenuChoice != 'Y' && mainMenuChoice != 'y' && mainMenuChoice != 'N' && mainMenuChoice != 'n') {
                printf("\nError. Please enter 'Y' or 'N'.");
            }
            fflush(stdin);
        } while (mainMenuChoice != 'Y' && mainMenuChoice != 'y' && mainMenuChoice != 'N' && mainMenuChoice != 'n');
    } while (mainMenuChoice == 'Y' || mainMenuChoice == 'y');

    printf("Exiting the program...\n");
    return 0;
}
//book menu
int BookMenu(FILE *fp, BOOKREC book){
int bookChoice, numRead;
    char bookMenuChoice;

    do {
        system("cls");
        printf("----BOOK RECORD----\n");
        printf("[1] Add a Book Record.\n[2] Search and Edit a Record.\n[3] Search and Delete a Record.\n[4] Display Book Records.\n[5] Exit.\n");
        printf("\nInput Choice: ");
        numRead = scanf("%d", &bookChoice);

        if (numRead == 1) {
            switch (bookChoice) {
                case 1:
                    DataEntry(fp, book);
                    break;
                case 2:
                    SearchandEdit(fp, book);
                    break;
                case 3:
                    //SearchandDelete(bookHead);
                    break;
                case 4:
                    DisplayBooks(fp, book);
                    break;
                case 5:
                    printf("Exiting the Book Menu...\n");
                    return 0;
                default:
                    printf("Invalid choice. Please input a number from 1-5.\n");
                    break;
            }
        } else {
            printf("Invalid choice. Please input a number from 1-5.\n");
            fflush(stdin);
        }

        do {
            printf("\nGo back to Book Menu? (Y/N): ");
            scanf(" %c", &bookMenuChoice);
            if (bookMenuChoice != 'Y' && bookMenuChoice != 'y' && bookMenuChoice != 'N' && bookMenuChoice != 'n') {
                printf("\nError. Please enter 'Y' or 'N'.");
            }
            fflush(stdin);
        } while (bookMenuChoice != 'Y' && bookMenuChoice != 'y' && bookMenuChoice != 'N' && bookMenuChoice != 'n');

    } while (bookMenuChoice == 'Y' || bookMenuChoice == 'y');

    printf("Returning to the main menu...\n");
    return 0;	
}
//create file
void Create(FILE *fp) {
	fp = fopen("bookrecord.dat", "wb");
	fclose(fp);
}
//add a book record
int DataEntry(FILE *fp, BOOKREC book) {
    int BN = 1, year = 1, numRead = 0, bookExists, typeChoice;
    float cost = 1;
    char title[TITLESIZE], author[AUTHORSIZE], type[TYPESIZE], avail;
    char confirm;
    
    
    fp = fopen("bookrecord.dat", "a+b"); 

	if ((fp, "a+b") == NULL)
	{
		printf("Error. unable to open file.\n");
	 	exit(1);
    }
    
    system("cls");
    printf("---ADD A BOOK RECORD---\n");
    fflush(stdin);

    do {
        printf("\nBOOK NUMBER (10000-99999): ");
        numRead = scanf("%d", &BN);
        if (numRead != 1 || BN < 10000 || BN > 99999) {
            printf("Error. Please enter a number from 10000 to 99999.\n");
            while (getchar() != '\n');
            continue;
        }
        
         // Check if book number already in use
        bookExists = 0; 
        while (fread(&book, sizeof(BOOKREC), 1, fp) == 1) {
            if (book.bookBookNum == BN) {
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
            while (getchar() != '\n');
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
        if (numRead != 1 || typeChoice < 1 || typeChoice > 3) {
            printf("Error. Please enter a number from 1 to 3.\n");
            while (getchar() != '\n');
            continue;
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
        }
    } while (numRead != 1 || typeChoice < 1 || typeChoice > 3);

    printf("Selected Book Type: %s\n", type);

    do {
        printf("BOOK COST: ");
        numRead = scanf("%f", &cost);
        if (numRead != 1 || cost < 0) {
            printf("Error. Please enter a valid non-negative cost.\n");
            while (getchar() != '\n');
        }
    } while (numRead != 1 || cost < 0);
    
    getchar(); 
    
    do {
        printf("BOOK AVAILABILITY ('Y' or 'N'): ");
        scanf(" %c", &avail);
        if (avail != 'Y' && avail != 'y' && avail != 'N' && avail != 'n') {
            printf("Error. Please enter 'Y' or 'N'.\n");
        }
        fflush(stdin);
    } while (avail != 'Y' && avail != 'y' && avail != 'N' && avail != 'n');
    
    // Confirm adding this record
    do {
        printf("\nConfirm adding this record? (Y/N): ");
        scanf(" %c", &confirm);
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            printf("Error. Please enter 'Y' or 'N'.\n");
        }
        fflush(stdin);
    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

    if (confirm == 'Y' || confirm == 'y') {
        
        // Store data
        book.bookBookNum = BN;
        strcpy(book.bookTitle, title);
        strcpy(book.bookAuthor, author);
        book.bookYear = year;
        strcpy(book.bookType, type);
        book.bookCost = cost;
        book.bookAvail = (avail == 'Y' || avail == 'y') ? 'Y' : 'N';

        // file write
        fwrite(&book, sizeof(BOOKREC), 1, fp);
        fflush(stdin);
        printf("Successfully added to record.\n");
        fclose(fp);
    } 
	else {
        printf("Adding book to record was cancelled.\n");
    }
    return 0;
}
//search and edit book
void SearchandEdit(FILE *fp, BOOKREC book) {
    int numRecord, typeChoice, numRead = 0, bookIndex = 0;
    char result, confirm, type[TYPESIZE];
    float cost;
    char BOOK[TITLESIZE];

	fp = fopen("bookrecord.dat", "r+b");

    if ((fp, "rb") == NULL) {
        system("cls");
        printf("Sorry. The book list is empty.\n");
        exit(1);
    }

    do {
        numRecord = 0;
        system("cls");
        printf("---SEARCH AND EDIT A BOOK---\n");
        printf("Enter Book Title/Author to Search: ");
        fflush(stdin);
        fgets(BOOK, TITLESIZE, stdin);
        BOOK[strlen(BOOK) - 1] = '\0';
		
		bookIndex = 0;
        while (fread(&book, sizeof(BOOKREC), 1, fp) == 1) {
            if (strcmpi(book.bookTitle, BOOK) == 0 || strcmpi(book.bookAuthor, BOOK) == 0) {
				printf("BOOK NUMBER: %d\n", book.bookBookNum);
                printf("TITLE: %s\n", book.bookTitle);
                printf("AUTHOR: %s\n", book.bookAuthor);
                printf("YEAR: %d\n", book.bookYear);
                printf("TYPE: %s\n", book.bookType);
                printf("COST: %.2f\n", book.bookCost);
                printf("AVAILABILITY: %c\n\n", book.bookAvail);
                numRecord++;
            }
            bookIndex++;
        }

        if (numRecord == 0) {
            printf("No books found with the given keyword.\n");
            system("pause");
            return;
        } else if (numRecord > 1) {
            printf("Multiple books found with the given title/author. Please input the book title instead.\n");
            system("pause");
        }
        rewind(fp);
    } while (numRecord != 1);
    
	bookIndex = 0;
    while (fread(&book, sizeof(BOOKREC), 1, fp) == 1) {
        if (strcmpi(book.bookTitle, BOOK) == 0 || strcmpi(book.bookAuthor, BOOK) == 0) {
            do {
                printf("\nDo you want to continue editing this book? (Y/N): ");
                scanf(" %c", &result);
                if (result != 'Y' && result != 'y' && result != 'N' && result != 'n') {
                    printf("Error. Please enter 'Y' or 'N'.\n");
                    getchar();
                }
                fflush(stdin);
            } while (result != 'Y' && result != 'y' && result != 'N' && result != 'n');

            if (result == 'Y' || result == 'y') {
                system("cls");
                do {
                    printf("ENTER NEW BOOK TYPE:\n");
                    printf("[1] Hardbound\n");
                    printf("[2] Paperback\n");
                    printf("[3] Springbound\n");
                    printf("Enter Choice: ");
                    numRead = scanf("%d", &typeChoice);
                    if (numRead != 1 || typeChoice < 1 || typeChoice > 3) {
                        printf("Error. Please enter a number from 1 to 3.\n");
                        while (getchar() != '\n');
                        continue;
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
                    }
                } while (numRead != 1 || typeChoice < 1 || typeChoice > 3);

                printf("Selected Book Type: %s\n", type);

                do {
                    printf("ENTER NEW BOOK COST: ");
                    numRead = scanf("%f", &cost);
                    if (numRead != 1 || cost < 0) {
                        printf("Error. Please enter a valid non-negative cost.\n");
                        while (getchar() != '\n');
                    }
                } while (numRead != 1 || cost < 0);

                do {
                    printf("\nConfirm editing this record? (Y/N): ");
                    scanf(" %c", &confirm);
                    if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
                        printf("Error. Please enter 'Y' or 'N'.\n");
                    }
                    fflush(stdin);
                } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

                if (confirm == 'Y' || confirm == 'y') {
                	//edit changes
                    book.bookCost = cost;
                    strcpy(book.bookType, type);
                    
                    //move fp to the beginning
                    fseek (fp, bookIndex * sizeof(BOOKREC), SEEK_SET);
                    fwrite(&book, sizeof(BOOKREC), 1, fp);
                    
                    printf("Record edited successfully.\n");
                } else {
                    printf("Editing of book was cancelled.\n");
                }
            } else {
                printf("Editing of book was cancelled.\n");
            }
            break;
        }
		bookIndex++;
    }
    fclose(fp);
}
//define gotoxy
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//display menu
void DisplayBooks (FILE *fp, BOOKREC book) {
	int choice, numRead = 0;
	system("cls");
	
	fp = fopen("bookrecord.dat", "rb");
	
	if ((fp, "rb") == NULL) {
        puts("Sorry. There are no book records to display.");
    }
    else {
    	do {
	system("cls");	
    printf("---DISPLAY BOOK RECORDS---\n");
    fflush(stdin);
    printf("[1]Display Books Available.\n");
    printf("[2]Display by Book Type.\n");
    printf("[3]Display by Book Author.\n");
    printf("[4]Display all Books.\n");
    printf("[5]Exit.\n\n");
    printf("Enter an option: ");
   	numRead = scanf("%d", &choice);
   	if (numRead != 1 || choice < 1 || choice > 5) {
            printf("Error. Please enter a number from 1 to 5.\n");
            while (getchar() != '\n');
            continue;
        }
	switch (choice) {
		case 1:
			//DisplayAvail(bookHead);
			break;
		case 2:
			//DisplayType(bookHead);
			break;
		case 3:
			//DisplayAuthor(bookHead);
			break;
		case 4:
			DisplayAll(fp, book);
			break;
		case 5:
			printf("Exiting the Display Menu...\n");
        	return;
			}	
	
		} while (numRead != 1 || choice < 1 || choice > 5);
	}
	fclose(fp);		
}
//display all books
void DisplayAll(FILE *fp, BOOKREC book) {
	int y = 4;
	system("cls");
	
	fp = fopen("bookrecord.dat", "rb");
	
	PrintDisplayTitle();
	while (fread(&book, sizeof(BOOKREC), 1, fp) == 1) {
		PrintDisplay(fp, book, y);
		y++;
	}
	fclose(fp);
	system("pause");
}
//print display
void PrintDisplay(FILE *fp, BOOKREC book, int y) {
    int x = 1;
	          
    gotoxy(x, y); printf("%d", book.bookBookNum);
    gotoxy(x+15, y); printf("%s", book.bookTitle);
    gotoxy(x+35, y); printf("%s", book.bookAuthor);
    gotoxy(x+55, y); printf("%d", book.bookYear);
    gotoxy(x+65, y); printf("%s", book.bookType);
    gotoxy(x+85, y); printf("%.2f", book.bookCost);
    gotoxy(x+100, y); printf("%c\n", book.bookAvail);                                                 
    y++;
}
void PrintDisplayTitle(void) {
                              
	int x = 1;
    int y = 2;
	printf("---BOOK RECORDS---");
    gotoxy(x, 2); printf("BOOK NUMBER");
    gotoxy(x+15, 2); printf("BOOK TITLE");
    gotoxy(x+35, 2); printf("BOOK AUTHOR");
    gotoxy(x+55, 2); printf("YEAR");
    gotoxy(x+65, 2); printf("BOOK TYPE");
    gotoxy(x+85, 2); printf("BOOK COST");
    gotoxy(x+100, 2); printf("BOOK AVAILABILITY");
}
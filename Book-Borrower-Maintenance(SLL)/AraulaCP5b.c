/*	Name: Angel Fredelle Mishka A. Araula
	course and section: BSIT - CCS3B
	Date Started: April 29, 2024
	Date Finished: May 15, 2024
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
typedef struct book *ndbook;
struct book
{
	int bookBookNum; 
	char bookTitle[TITLESIZE];
	char bookAuthor[AUTHORSIZE];
	int bookYear;
	char bookType[TYPESIZE];
	float bookCost;
	char bookAvail;
	ndbook next;
} BOOKNODE;
//borrower structure
typedef struct borrower *ndborr;
struct borrower
{
	int borrNum;
	char borrLname[NAMESIZE];
	char borrFname[NAMESIZE];
	int noBooks;
	ndborr next;	
} BORROWERNODE;
//functions
int BookMenu(ndbook *bookHead);
int BorrMenu(ndborr *borrHead);
//book functions
int DataEntry(ndbook *bookHead);
void SearchandEdit(ndbook *bookHead);
void SearchandDelete(ndbook *bookHead);
void DisplayBooks (ndbook *bookHead);
void DisplayAvail(ndbook *bookHead);
void DisplayType(ndbook *bookHead);
void DisplayAuthor(ndbook *bookHead);
void DisplayAll(ndbook *bookHead);
void PrintDisplay(ndbook book, int y);
void PrintDisplayTitle(void);
//Borrower Functions
int BorrDataEntry(ndborr *borrHead);
void BorrSearchandEdit(ndborr *borrHead);
void BorrSearchandDelete(ndborr *borrHead);
void BorrDisplay(ndborr *borrHead);
void DisplayBorr (ndborr *borrHead);
void DisplayLnameBorr(ndborr *borrHead);
void DisplayAllBorr(ndborr *borrHead);
void PrintDisplayBorr(ndborr borrower, int y);
void PrintDisplayTitleBorr(void);
//main
int main(void) {
	ndbook bookHead=NULL;
    ndborr borrHead=NULL;
    
    int choice, numRead;
    char mainMenuChoice;

    do {
        system("cls");
        printf("----MAIN MENU----\n");
        printf("[1] Maintenance of Book Records.\n[2] Maintenance of Borrower Records.\n[3] Exit this Program.\n");
        printf("\nInput Choice: ");
        numRead = scanf("%d", &choice);

        if (numRead == 1) {
            switch (choice) {
                case 1:
                    BookMenu(&bookHead);
                    break;
                case 2:
                    BorrMenu(&borrHead);
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
int BookMenu(ndbook *bookHead){
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
                    DataEntry(bookHead);
                    break;
                case 2:
                    SearchandEdit(bookHead);
                    break;
                case 3:
                    SearchandDelete(bookHead);
                    break;
                case 4:
                    DisplayBooks(bookHead);
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
//borrower menu
int BorrMenu(ndborr *borrHead) {
int borrChoice, numRead;
    char borrMenuChoice;

    do {
        system("cls");
        printf("----BORROWER RECORD----\n");
        printf("[1] Add a Borrower.\n[2] Search and Edit a Borrower.\n[3] Search and Delete a Borrower.\n[4] Display Borrowers.\n[5] Go Back to the previous Menu.\n[6] Exit.\n");
        printf("\nInput Choice: ");
        numRead = scanf("%d", &borrChoice);

        if (numRead == 1) {
            switch (borrChoice) {
                case 1:
                    BorrDataEntry(borrHead);
                    break;
                case 2:
                    BorrSearchandEdit(borrHead);
                    break;
                case 3:
                    BorrSearchandDelete(borrHead);
                    break;
                case 4:
                    BorrDisplay(borrHead);
                    break;
                case 5:
                    printf("Going back to the Main Menu...\n");
                    return 0;
                case 6:
                    printf("Exiting the Borrower Menu...\n");
                    return 0;
                default:
                    printf("Invalid choice. Please input a number from 1-6.\n");
                    break;
            }
        } else {
            printf("Invalid choice. Please input a number from 1-6.\n");
            fflush(stdin);
        }

        do {
            printf("\nGo back to Borrower Menu? (Y/N): ");
            scanf(" %c", &borrMenuChoice);
            if (borrMenuChoice != 'Y' && borrMenuChoice != 'y' && borrMenuChoice != 'N' && borrMenuChoice != 'n') {
                printf("\nError. Please enter 'Y' or 'N'.");
            }
            fflush(stdin);
        } while (borrMenuChoice != 'Y' && borrMenuChoice != 'y' && borrMenuChoice != 'N' && borrMenuChoice != 'n');

    } while (borrMenuChoice == 'Y' || borrMenuChoice == 'y');

    printf("Returning to the main menu...\n");
    return 0;
}
//add a book record
int DataEntry(ndbook *bookHead) {
    ndbook BH, bTemp, p;
    int BN = 1, year = 1, numRead = 0, bookExists, typeChoice;
    float cost = 1;
    char title[TITLESIZE], author[AUTHORSIZE], type[TYPESIZE], avail;
    char confirm;
    
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
        BH = *bookHead; 
        while (BH != NULL) {
            if (BH->bookBookNum == BN) {
                bookExists = 1;
                break;
            }
            BH = BH->next;
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
        // Allocate memory
        bTemp = malloc(sizeof(BOOKNODE));
        if (bTemp == NULL) {
            printf("Memory allocation failed. Book not added.\n");
            return -1;
        }
        
        // Store data
        bTemp->bookBookNum = BN;
        strcpy(bTemp->bookTitle, title);
        strcpy(bTemp->bookAuthor, author);
        bTemp->bookYear = year;
        strcpy(bTemp->bookType, type);
        bTemp->bookCost = cost;
        bTemp->bookAvail = (avail == 'Y' || avail == 'y') ? 'Y' : 'N';
        bTemp->next = NULL;

        // Insertion of nodes
        if (*bookHead == NULL || (*bookHead)->bookBookNum > bTemp->bookBookNum) {
            bTemp->next = *bookHead;
            *bookHead = bTemp;
        } else {
            p = *bookHead;
            while (p->next != NULL && p->next->bookBookNum < bTemp->bookBookNum) {
                p = p->next;
            }
            bTemp->next = p->next;
            p->next = bTemp;
        }

        printf("Successfully added to record.\n");
    } else {
        printf("Adding book to record was cancelled.\n");
    }
    return 0;
}

//search and edit book
void SearchandEdit(ndbook *bookHead) {
    int numRecord, typeChoice, numRead = 0;
    char result, confirm, type[TYPESIZE];
    float cost;
    char BOOK[TITLESIZE];

    if (*bookHead == NULL) {
        system("cls");
        printf("Sorry. The book list is empty.\n");
        return;
    }

    do {
        numRecord = 0;
        system("cls");
        printf("---SEARCH AND EDIT A BOOK---\n");
        printf("Enter Book Title/Author to Search: ");
        fflush(stdin);
        fgets(BOOK, TITLESIZE, stdin);
        BOOK[strlen(BOOK) - 1] = '\0';

        ndbook p = *bookHead;
        while (p != NULL) {
            if (strcmpi(p->bookTitle, BOOK) == 0 || strcmpi(p->bookAuthor, BOOK) == 0) {
                printf("BOOK NUMBER: %d\n", p->bookBookNum);
                printf("TITLE: %s\n", p->bookTitle);
                printf("AUTHOR: %s\n", p->bookAuthor);
                printf("YEAR: %d\n", p->bookYear);
                printf("TYPE: %s\n", p->bookType);
                printf("COST: %.2f\n", p->bookCost);
                printf("AVAILABILITY: %c\n\n", p->bookAvail);
                numRecord++;
            }
            p = p->next;
        }

        if (numRecord == 0) {
            printf("No books found with the given keyword.\n");
            system("pause");
            return;
        } else if (numRecord > 1) {
            printf("Multiple books found with the given title/author. Please input the book title instead.\n");
            system("pause");
        }
    } while (numRecord != 1);

    ndbook p = *bookHead;
    while (p != NULL) {
        if (strcmpi(p->bookTitle, BOOK) == 0 || strcmpi(p->bookAuthor, BOOK) == 0) {
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
                    p->bookCost = cost;
                    strcpy(p->bookType, type);
                    printf("Record edited successfully.\n");
                } else {
                    printf("Editing of book was cancelled.\n");
                }
            } else {
                printf("Editing of book was cancelled.\n");
            }
            break;
        }
        p = p->next;
    }
}
//search and delete book
void SearchandDelete(ndbook *bookHead) {
    ndbook p, q;
    int numRecord;
    char confirm;
    char BOOK[TITLESIZE];

    if (*bookHead == NULL) {
        system("cls");
        printf("Sorry. The book list is empty.\n");
        return;
    }

    do {
        numRecord = 0;
        system("cls");
        printf("---SEARCH AND DELETE A BOOK---\n");
        printf("Enter Book Title/Author to Search: ");
        fflush(stdin);
        fgets(BOOK, TITLESIZE, stdin);
        BOOK[strlen(BOOK) - 1] = '\0';

        p = *bookHead;
        q = NULL;
        while (p != NULL) {
            if (strcmpi(p->bookTitle, BOOK) == 0 || strcmpi(p->bookAuthor, BOOK) == 0) {
                printf("BOOK NUMBER: %d\n", p->bookBookNum);
                printf("TITLE: %s\n", p->bookTitle);
                printf("AUTHOR: %s\n", p->bookAuthor);
                printf("YEAR: %d\n", p->bookYear);
                printf("TYPE: %s\n", p->bookType);
                printf("COST: %.2f\n", p->bookCost);
                printf("AVAILABILITY: %c\n\n", p->bookAvail);
                numRecord++;
            }
            p = p->next;
        }

        if (numRecord == 0) {
            printf("No books found with the given keyword.\n");
            system("pause");
            return;
        } else if (numRecord > 1) {
            printf("Multiple books found with the given title/author. Please input the book title instead.\n");
            system("pause");
        }
    } while (numRecord != 1);
    
    p = *bookHead;
    q = NULL;
    while (p != NULL) {
        if (strcmpi(p->bookTitle, BOOK) == 0 || strcmpi(p->bookAuthor, BOOK) == 0) {
            // Confirm deletion
            do {
                printf("\nConfirm deleting this record? (Y/N): ");
                scanf(" %c", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    if (q == NULL) {
                    	//delete first node
                        *bookHead = p->next;
                    } 
					else {
						//delete middle or end
                        q->next = p->next;
                    }
                    free(p);
                    printf("Record deleted successfully.\n");
                    return;
                } else if (confirm == 'N' || confirm == 'n') {
                    printf("Deletion of book was cancelled.\n");
                    return;
                } else {
                    printf("Error. Please enter 'Y' or 'N'.\n");
                }
                fflush(stdin);
            } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
        }
        //traverse the list. q is the previous node.
        q = p;
        p = p->next;
    }
}
//define gotoxy
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//display menu
void DisplayBooks (ndbook *bookHead) {
	int choice, numRead = 0;
	system("cls");
	if (*bookHead == NULL) {
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
			DisplayAvail(bookHead);
			break;
		case 2:
			DisplayType(bookHead);
			break;
		case 3:
			DisplayAuthor(bookHead);
			break;
		case 4:
			DisplayAll(bookHead);
			break;
		case 5:
			printf("Exiting the Display Menu...\n");
        	return;
			}	
	
		} while (numRead != 1 || choice < 1 || choice > 5);
	}		
}
//display available books
void DisplayAvail(ndbook *bookHead) {
	int AvailCount = 0;
	int y = 4;
    ndbook p = *bookHead;
    system("cls");
    
    PrintDisplayTitle();
    while (p != NULL) {
        if (p->bookAvail == 'Y' || p->bookAvail == 'y') {
            PrintDisplay(p, y);
            AvailCount++;
            y++;
        }
        p = p->next;
    }
    
    if (AvailCount == 0) {
    	system("cls");
        printf("No available books.\n");
    }
	system("pause");   
}
//display type books
void DisplayType(ndbook *bookHead) {
	ndbook p = *bookHead;
	int typeChoice, typeCount = 0, y = 4, numRead = 0;
	system("cls");
	
        do {
        printf("CHOOSE A BOOK TYPE TO DISPLAY:\n");
        printf("[1] Hardbound\n");
        printf("[2] Paperback\n");
        printf("[3] Springbound\n");
        printf("[4] Exit.\n");
        printf("Enter Choice: ");
        numRead = scanf("%d", &typeChoice);
        if (numRead != 1 || typeChoice < 1 || typeChoice > 4) {
            printf("Error. Please enter a number from 1 to 3.\n");
            while (getchar() != '\n');
            continue;
        }
        	switch (typeChoice) {
            	case 1:
            		system("cls");
            		PrintDisplayTitle();
                	while (p != NULL) {
                		if (strcmpi(p->bookType, "Hardbound") == 0) {
                			PrintDisplay(p, y);
                			typeCount++;
                			y++;
						}
						p = p->next;
					}
					if (typeCount == 0) {
						system("cls");
        				printf("No Hardbound books.\n");
    				}
					system("pause");
					break;  
            	case 2:
            		system("cls");
            		PrintDisplayTitle();
                	while (p != NULL) {
                		if (strcmpi(p->bookType, "Paperback") == 0) {
                			PrintDisplay(p, y);
                			typeCount++;
                			y++;
						}
						p = p->next;
					}
					if (typeCount == 0) {
						system("cls");
        				printf("No Paperback books.\n");
    				}
					system("pause");
					break;  
            	case 3:
            		system("cls");
            		
            		PrintDisplayTitle();
                	while (p != NULL) {
                		if (strcmpi(p->bookType, "Springbound") == 0) {
                			PrintDisplay(p, y);
                			typeCount++;
                			y++;
						}
						p = p->next;
					}
					if (typeCount == 0) {
						system("cls");
        				printf("No Springbound books.\n");
    				}
					system("pause");
					break;  
				case 4:
					printf("Exiting book type menu...\n");
					return;
        }
	} while (numRead != 1 || typeChoice < 1 || typeChoice > 4);
}
//display by author books
void DisplayAuthor(ndbook *bookHead) {
	ndbook p = *bookHead;
	int authorCount = 0, y = 4;
	char author[AUTHORSIZE];
	system("cls");
            fflush(stdin);
            printf("ENTER BOOK AUTHOR TO DISPLAY: ");
            fgets(author, AUTHORSIZE, stdin);
            author[strlen(author) - 1] = '\0';
            
            system("cls");
            PrintDisplayTitle();
        	while (p != NULL) {
        		if (strcmpi(p->bookAuthor, author) == 0) {
                  PrintDisplay(p, y);
				  authorCount++;
				  y++;  
                }
                p = p->next;
			}
            
            if (authorCount == 0) {
            	system("cls");
                printf("No books found with the given author.\n");
            }
            system("pause");
}
//display all books
void DisplayAll(ndbook *bookHead) {
	ndbook p = *bookHead;
	int y = 4;
	system("cls");
	
	PrintDisplayTitle();
	while (p != NULL) {
		PrintDisplay(p, y);
		y++;
		p = p->next;
	}
	system("pause");
}
//print display
void PrintDisplay(ndbook book, int y) {
    int x = 1;
                
    gotoxy(x, y); printf("%d", book->bookBookNum);
    gotoxy(x+15, y); printf("%s", book->bookTitle);
    gotoxy(x+35, y); printf("%s", book->bookAuthor);
    gotoxy(x+55, y); printf("%d", book->bookYear);
    gotoxy(x+65, y); printf("%s", book->bookType);
    gotoxy(x+85, y); printf("%.2f", book->bookCost);
    gotoxy(x+100, y); printf("%c\n", book->bookAvail);
                                                      
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
//BORROWER FUNCTIONS
//add a borrower
int BorrDataEntry(ndborr *borrHead) {
	int borrID, NoB, numRead = 0, borrExists;
	char borrFN[NAMESIZE], borrLN[NAMESIZE], confirm;
	ndborr BH, bTemp, p;
	
	system("cls");
    printf("---ADD A BORROWER RECORD---\n");
    fflush(stdin);

    do {
        printf("\nBORROWER NUMBER (10000-99999): ");
        numRead = scanf("%d", &borrID);
        if (numRead != 1 || borrID < 10000 || borrID > 99999) {
            printf("Error. Please enter a number from 10000 to 99999.\n");
            while (getchar() != '\n');
            continue;
        }
        
        // Check if borrower number already in use
        borrExists = 0;
        BH = *borrHead; 
        while (BH != NULL) {
            if (BH->borrNum == borrID) {
                borrExists = 1;
                break;
            }
            BH = BH->next;
        }
        if (borrExists) {
            printf("Error. Borrower number %d already exists. Please enter a different borrower number.\n", borrID);
        }
    } while (numRead != 1 || borrID < 10000 || borrID > 99999 || borrExists);
    
    getchar();
    
    printf("BORROWER's FIRST NAME: ");
    fgets(borrFN, NAMESIZE, stdin);
    borrFN[strlen(borrFN) - 1] = '\0';

    printf("BORROWER's LAST NAME: ");
    fgets(borrLN, NAMESIZE, stdin);
    borrLN[strlen(borrLN) - 1] = '\0';
    
    do {
        printf("NUMBER OF BOOKS BORROWED: ");
        numRead = scanf("%d", &NoB);
        if (numRead != 1 || NoB < 1) {
            printf("Error. Please enter a non-negative number.\n");
            while (getchar() != '\n');
        }
    } while (numRead != 1 || NoB < 1);
    getchar();
    
    // Confirm adding this borrower record
    do {
        printf("\nConfirm adding this record? (Y/N): ");
        scanf(" %c", &confirm);
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            printf("Error. Please enter 'Y' or 'N'.\n");
        }
        fflush(stdin);
    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

    if (confirm == 'Y' || confirm == 'y') {
        // Allocate memory
        bTemp = malloc(sizeof(BORROWERNODE));
        if (bTemp == NULL) {
            printf("Memory allocation failed. Borrower not added.\n");
            return -1;
        }
        
        // Store data
        bTemp->borrNum = borrID;
        strcpy(bTemp->borrFname, borrFN);
        strcpy(bTemp->borrLname, borrLN);
        bTemp->noBooks = NoB;
        bTemp->next = NULL;

        // Insertion of nodes
        if (*borrHead == NULL || (*borrHead)->borrNum > bTemp->borrNum) {
            bTemp->next = *borrHead;
            *borrHead = bTemp;
        } else {
            p = *borrHead;
            while (p->next != NULL && p->next->borrNum < bTemp->borrNum) {
                p = p->next;
            }
            bTemp->next = p->next;
            p->next = bTemp;
        }

        printf("Successfully added to record.\n");
    } else {
        printf("Adding book to record was cancelled.\n");
    }
    return 0;
}
//search and edit a borrower
void BorrSearchandEdit (ndborr *borrHead) {
    int numRecord, numRead = 0;
    char result, confirm;
    char BORROWER[NAMESIZE], borrFN[NAMESIZE];

    if (*borrHead == NULL) {
        system("cls");
        printf("Sorry. The borrower list is empty.\n");
        return;
    }

    do {
        numRecord = 0;
        system("cls");
        printf("---SEARCH AND EDIT A BORROWER---\n");
        printf("Enter Borrower's FIRST/LAST NAME to Search: ");
        fflush(stdin);
        fgets(BORROWER, NAMESIZE, stdin);
        BORROWER[strlen(BORROWER) - 1] = '\0';

        ndborr p = *borrHead;
        while (p != NULL) {
            if (strcmpi(p->borrFname, BORROWER) == 0 || strcmpi(p->borrLname, BORROWER) == 0) {
                printf("BORROWER NUMBER: %d\n", p->borrNum);
                printf("BORROWER's FIRST NAME: %s\n", p->borrFname);
                printf("BORROWER's LAST NAME: %s\n", p->borrLname);
                printf("NO. BOOKS BORROWED: %d\n\n", p->noBooks);
                numRecord++;
            }
            p = p->next;
        }

        if (numRecord == 0) {
            printf("No borrowers found with the given keyword.\n");
            system("pause");
            return;
        } else if (numRecord > 1) {
            printf("Multiple borrowers found with the given last name. Please input the borrower's first name instead.\n");
            system("pause");
        }
    } while (numRecord != 1);
	
	ndborr p = *borrHead;
    while (p != NULL) {
        if (strcmpi(p->borrFname, BORROWER) == 0 || strcmpi(p->borrLname, BORROWER) == 0) {
            do {
                printf("\nDo you want to continue editing this borrower? (Y/N): ");
                scanf(" %c", &result);
                while (getchar() != '\n');
                
                if (result != 'Y' && result != 'y' && result != 'N' && result != 'n') {
                    printf("Error. Please enter 'Y' or 'N'.\n");
                }
                fflush(stdin);
            } while (result != 'Y' && result != 'y' && result != 'N' && result != 'n');

            if (result == 'Y' || result == 'y') {
                system("cls");

                    printf("ENTER NEW FIRST NAME: ");
                    fgets(borrFN, NAMESIZE, stdin);
    				borrFN[strlen(borrFN) - 1] = '\0';

                do {
                    printf("\nConfirm editing this record? (Y/N): ");
                    scanf(" %c", &confirm);
                    if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
                        printf("Error. Please enter 'Y' or 'N'.\n");
                    }
                    fflush(stdin);
                } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

                if (confirm == 'Y' || confirm == 'y') {
                    strcpy(p->borrFname, borrFN);
                    printf("Borrower edited successfully.\n");
                } else {
                    printf("Editing of borrower was cancelled.\n");
                }
            } else {
                printf("Editing of borrower was cancelled.\n");
            }
            break;
        }
        p = p->next;
    }	
}
//search and delete a borrower
void BorrSearchandDelete (ndborr *borrHead) {
   ndborr p, q;
    int numRecord;
    char confirm;
    char BORROWER[NAMESIZE];

    if (*borrHead == NULL) {
        system("cls");
        printf("Sorry. The borrower list is empty.\n");
        return;
    }

    do {
        numRecord = 0;
        system("cls");
        printf("---SEARCH AND DELETE A BORROWER---\n");
        printf("Enter Borrower's First/Last Name to Search: ");
        fflush(stdin);
        fgets(BORROWER, NAMESIZE, stdin);
        BORROWER[strlen(BORROWER) - 1] = '\0';

        p = *borrHead;
        q = NULL;
        while (p != NULL) {
            if (strcmpi(p->borrLname, BORROWER) == 0 || strcmpi(p->borrFname, BORROWER) == 0) {
                printf("BORROWER NUMBER: %d\n", p->borrNum);
                printf("BORROWER's FIRST NAME: %s\n", p->borrFname);
                printf("BORROWER's LAST NAME: %s\n", p->borrLname);
                printf("NO. BOOKS BORROWED: %d\n\n", p->noBooks);
                numRecord++;
            }
            p = p->next;
        }

        if (numRecord == 0) {
            printf("No borrowers found with the given keyword.\n");
            system("pause");
            return;
        } else if (numRecord > 1) {
            printf("Multiple borrowers found with the given name. Please input the borrower's first name instead.\n");
            system("pause");
        }
    } while (numRecord != 1);
    
    p = *borrHead;
    q = NULL;
    while (p != NULL) {
        if (strcmpi(p->borrLname, BORROWER) == 0 || strcmpi(p->borrFname, BORROWER) == 0) {
            // Confirm deletion
            do {
                printf("\nConfirm deleting this record? (Y/N): ");
                scanf(" %c", &confirm);
                if (confirm == 'Y' || confirm == 'y') {
                    if (q == NULL) {
                    	//delete first node
                        *borrHead = p->next;
                    } 
					else {
						//delete middle or end node
                        q->next = p->next;
                    }
                    free(p);
                    printf("Record deleted successfully.\n");
                    return;
                } else if (confirm == 'N' || confirm == 'n') {
                    printf("Deletion of borrower was cancelled.\n");
                    return;
                } else {
                    printf("Error. Please enter 'Y' or 'N'.\n");
                }
                fflush(stdin);
            } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
        }
        q = p;
        p = p->next;
    }
}
//Display of borrowers menu
void BorrDisplay(ndborr *borrHead) {
	int choice, numRead = 0;
	system("cls");
	if (*borrHead == NULL) {
        puts("Sorry. There are no borrower records to display.");
    }
    else {
    	do {
	system("cls");	
    printf("---DISPLAY BORROWER RECORDS---\n");
    fflush(stdin);
    printf("[1]Display Borrowers with the same LAST NAME.\n");
    printf("[2]Display all Borrowers.\n");
    printf("[3]Exit.\n\n");
    printf("Enter an option: ");
   	numRead = scanf("%d", &choice);
   	if (numRead != 1 || choice < 1 || choice > 3) {
            printf("Error. Please enter a number from 1 to 3.\n");
            while (getchar() != '\n');
            continue;
        }
	switch (choice) {
		case 1:
			DisplayLnameBorr(borrHead);
			break;
		case 2:
			DisplayAllBorr(borrHead);
			break;
		case 3:
			printf("Exiting the Display Menu...\n");
        	return;
			}	
	
		} while (numRead != 1 || choice < 1 || choice > 5);
	}			
}
//display last name borrower
void DisplayLnameBorr(ndborr *borrHead) {
	ndborr p = *borrHead;
	int LnameCount = 0, y = 4;  
	char Lname[NAMESIZE];
	system("cls");
            fflush(stdin);
            printf("ENTER BORROWER's LAST NAME TO DISPLAY: ");
            fgets(Lname, NAMESIZE, stdin);
            Lname[strlen(Lname) - 1] = '\0';
            
            system("cls");
            PrintDisplayTitleBorr();
        	while (p != NULL) {
        		if (strcmpi(p->borrLname, Lname) == 0) {
                  PrintDisplayBorr(p, y);
				  LnameCount++;
				  y++;  
                }
                p = p->next;
			}
            
            if (LnameCount == 0) {
            	system("cls");
                printf("No borrowers found with the given last name.\n");
            }
            system("pause");
}
//display all borrowers
void DisplayAllBorr(ndborr *borrHead) {
	ndborr p = *borrHead;
	int y = 4;
	system("cls");
	
	PrintDisplayTitleBorr();
	while (p != NULL) {
		PrintDisplayBorr(p, y);
		y++;
		p = p->next;
	}
	system("pause");
}
//print display borrower
void PrintDisplayBorr(ndborr borrower, int y) {
    int x = 1;
                
    gotoxy(x, y); printf("%d", borrower->borrNum);
    gotoxy(x+30, y); printf("%s", borrower->borrFname);
    gotoxy(x+65, y); printf("%s", borrower->borrLname);
    gotoxy(x+95, y); printf("%d\n", borrower->noBooks);                                         
    y++;
}
void PrintDisplayTitleBorr(void) {                          
	int x = 1;
    int y = 2;
    
	printf("---BORROWER RECORDS---");
    gotoxy(x, 2); printf("BORROWER NUMBER");
    gotoxy(x+30, 2); printf("BORROWER's FIRST NAME");
    gotoxy(x+65, 2); printf("BORROWER's LAST NAME");
    gotoxy(x+95, 2); printf("NO BOOKS BORROWED");
}
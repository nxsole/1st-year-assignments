/*	Name: Angel Fredelle Mishka A. Araula
	Date Started: Febuary 23, 2023
	Date Finished: Febuary 26, 2023
	Summary: inputs 2 arrays and find sum, difference,
			 product, quotient, number of even and odd numbers, average,
			 and number of largest and smallest numbers of the arrays.*/
#include <stdio.h>
#define SIZE 5

void InputArray(int arr[]);
void CalculateArray(int Array1[SIZE], int Array2[SIZE], int Sum[], int Difference[], int Product[],
 int Quotient[], int Remainder[], int *Even1, int *Odd1, int *Even2, int *Odd2, float *average1,float *average2, int *largest1, int *smallest1, int *largest2, int *smallest2);
void OutputArray(int Array1[SIZE], int Array2[SIZE], int Sum[], int Difference[], int Product[], int Quotient[],
 int Remainder[], int Even1, int Odd1, int Even2, int Odd2, float Average1,float Average2, int Largest1, int Smallest1, int Largest2, int Smallest2);

int main(void) {
    int Array1[SIZE], Array2[SIZE], Sum[SIZE], Difference[SIZE], Product[SIZE], 
	Quotient[SIZE], Remainder[SIZE], Even1, Odd1, Even2, Odd2,Largest1, Smallest1, Largest2, Smallest2;
    float Average1, Average2;
    char choice;
    do {
    printf("Please enter 5 numbers for array 1 (range of 1-100):\n");
    InputArray(Array1);
    printf("Please enter 5 numbers for array 2 (range of 1-100):\n");
    InputArray(Array2);
    CalculateArray(Array1, Array2, Sum, Difference, Product, Quotient, Remainder, &Even1, &Odd1, &Even2, &Odd2, &Average1, &Average2,&Largest1, &Smallest1, &Largest2, &Smallest2);
    OutputArray(Array1, Array2, Sum, Difference, Product, Quotient, Remainder, Even1, Odd1, Even2, Odd2, Average1, Average2, Largest1, Smallest1, Largest2, Smallest2); 
  do {
    printf("Do you want to repeat the process (Y/N): ");
    scanf(" %c", &choice);
        if (choice != 'Y' && choice != 'N') {
            printf("Error. Please choose 'Y' or 'N'.\n");
            }
        } while (choice != 'Y' && choice != 'N');
    } while (choice == 'Y');
    printf("Terminating this application.\n");
}

void InputArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        do {
            scanf("%d", &arr[i]);
            if (arr[i] < 1 || arr[i] > 100) {
                printf("(Sorry, this number is out of range. Please enter another number.)\n");
            }
        } while (arr[i] < 1 || arr[i] > 100);
    }
    return;
}

void CalculateArray(int Array1[SIZE], int Array2[SIZE], int Sum[], int Difference[],
int Product[], int Quotient[], int Remainder[], int *Even1, int *Odd1, int *Even2, int *Odd2, float *average1,float *average2,int *largest1, int *smallest1, int *largest2, int *smallest2) {
    int sum1=0, sum2=0;
	*Even1 = 0; *Odd1 = 0;*Even2 = 0; *Odd2 = 0;
	*largest1= Array1[0]; *smallest1 = Array1[0]; *largest2= Array2[0]; *smallest2 = Array2[0];
    
    for (int i = 0; i < SIZE; i++) {
    	//sum difference product quotient remainder
        Sum[i] = Array1[i] + Array2[i];
        Difference[i] = Array1[i] - Array2[i];
        Product[i] = Array1[i] * Array2[i];
        Quotient[i] = Array1[i] / Array2[i];
        Remainder[i] = Array1[i] % Array2[i];
        //Even Odd
    	if (Array1[i] % 2 == 0)
            (*Even1)++;
        else
            (*Odd1)++;
        if (Array2[i] % 2 == 0)
            (*Even2)++;
        else
            (*Odd2)++;
		//Average
        sum1 += Array1[i];
        sum2 += Array2[i];
        //Largest Smallest
        if (Array1[i] > *largest1) {
            *largest1 = Array1[i];
        }
        if (Array1[i] < *smallest1) {
            *smallest1 = Array1[i];
        }
        if (Array2[i] > *largest2) {
            *largest2 = Array2[i];
        }
        if (Array2[i] < *smallest2) {
            *smallest2 = Array2[i];
        }
    }
	*average1 = (float)sum1 / SIZE;
	*average2 = (float)sum2 / SIZE;
	
	return;
}

void OutputArray(int Array1[SIZE], int Array2[SIZE], int Sum[], int Difference[], int Product[],
int Quotient[],int Remainder[], int Even1, int Odd1, int Even2, int Odd2, float Average1,float Average2, int Largest1, int Smallest1, int Largest2, int Smallest2) {
    printf("\nHere are the numbers that you entered and the sum, difference, product, quotient, and remainder:\n");
    printf("Array 1\tArray 2\tSum\tDifference\tProduct\tQuotient\tRemainder\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", Array1[i], Array2[i], Sum[i], Difference[i], Product[i], Quotient[i], Remainder[i]);
    }
    printf("\nArray 1:\n");
    printf("Number of even numbers: %d\n", Even1);
    printf("Number of odd numbers: %d\n", Odd1);
    printf("Average: %.1f\n", Average1);
    printf("Largest number: %d\n", Largest1);
    printf("Smallest number: %d\n\n", Smallest1);
    
    printf("Array 2:\n");
    printf("Number of even numbers: %d\n", Even2);
    printf("Number of odd numbers: %d\n", Odd2);
    printf("Average: %.1f\n", Average2);
    printf("Largest number: %d\n", Largest2);
    printf("Smallest number: %d\n\n", Smallest2);
    
    return;
}
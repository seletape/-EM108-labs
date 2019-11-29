#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* structured type definition */
typedef struct cust_type_tag
{
char name[20];
char brand[20];
char hobby_name[20];
char price[20];
char discount[20];
} cust_type;
/* declarations */
/* function that reads data from a file, stores it in
an array and returns the number of records read*/
//Shop 1
int read_records1 (char* items1, cust_type cust[]);
//Shop 2
int read_records2 (char* items2, cust_type cust[]);
/* function that computes the average for each
custent given the array with cust info and stores the
results in the same array */

//void write_records (char* items1.txt,
//cust_type cust[], int size);
/* function that prints the custentnames, grades and
their average marks */
//void print_results (cust_type cust[], int size);

/* main function */
int main()
{
/* 1-dimensional array that stores custent
related data for all registered custents */
cust_type cust[5000];
/* no current registered custents (no records) */
int norecs = 0;
/* welcome message */
printf("Welcome to the program!\n");
/* read records */
norecs = read_records("records.txt", cust);
/* compute the averages */
//compute_average(cust, norecs);
/* write data to a file */
write_records("results.txt", cust, norecs);
/* print results */
print_results(cust, norecs);
printf("Goodbye!\n");
return (EXIT_SUCCESS);
}

/* function definitions */
int read_records1 (char* items1, cust_type cust[])
{
FILE* fp;
int norecs = 0;
char ch;
float price, discount;
/* open file */
fp = fopen(items1, "r");
while(!feof(fp))
{
/* read on record from file */
&cust[norecs].name, &ch,
&cust[norecs].brand, &ch,
&cust[norecs].hobby_name, &ch
&cust[norecs].price, %f,
&cust[norecs].discount, &ch);
/* increase the number of records read */
norecs++;
}
/* close file */
fclose(fp);
return norecs;
}

int read_records2 (char* items2, cust_type cust[])
{
FILE* fp;
int norecs = 0;
char ch;
/* open file */
fp = fopen(items2, "r");
while(!feof(fp))
{
/* read on record from file */
fscanf(items2, "%c%c%c%f%f",
&cust[norecs].name, &ch,
&cust[norecs].brand, &ch,
&cust[norecs].hobby_name, &ch
cust[norecs].price, %f,
&cust[norecs].discount, &ch);
/* increase the number of records read */
norecs++;
}
/* close file */
fclose(fp);
return norecs;
}




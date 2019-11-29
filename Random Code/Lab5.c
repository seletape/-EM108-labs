#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

 struct car
{
int year;
char number[9];
char number[10];
float engine;
} car_type;


/* function declaration */
void printCar( struct Cars Car );

int main( ) {

   struct Car Car1;        /* Declare Car1 of type Car */
   struct Car Car2;        /* Declare Car2 of type Car */

   /* Car 1 specification */
   strcpy( Car1.year, "1991");
   strcpy( Car1.number, "91D2134");
   strcpy( Car1.colour, "red");
   strcpy( Car1.engine, "1.5";

   /* Car 2 specification */
   strcpy( Car2.year, "Telecom Billing");
   strcpy( Car2.number, "Zara Ali");
   strcpy( Car2.colour, "Telecom Billing Tutorial");
   Car2.Car_id = 6495700;

   /* print Car1 info */
   printCar( Car1 );

   /* Print Car2 info */
   printCar( Car2 );

   return 0;
}

void printCar( struct Cars Car ) {

   printf( "Car year : %d\n", Car.year);
   printf( "Car number : %s\n", Car.number);
   printf( "Car colour : %s\n", Car.colour);
   printf( "Car engine : %f\n", Car.engine);
}

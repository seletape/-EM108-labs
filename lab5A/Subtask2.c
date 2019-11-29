

#include <stdio.h>

#include <stdlib.h>

#include <string.h>





float vx(float h, float t);

float vy(float In_h, float v, float t);

void welcome();



float vx(float h, float t)

 {
/* standard C libraries */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>




float vx(float h, float t);

float vy(float In_h, float v, float t);

void welcome();



float vx(float h, float t)

 {

 return(h*t);

 }



float vy(float In_h, float v, float t)

 {

 return (In_h+((v*t)+(t*t)*(-9.81)));

 }



void welcome()

 {

 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");

 }



int main()

 {



  float In_h, h, v, x, y, t;

  FILE* p;





  welcome();





  printf("\nEnter Initial height:\n");

  scanf("%f", &In_h);

  printf("Enter Initial Horizontal Velocity?\n");

  scanf("%f", &h);

  printf("Enter Initial Vertical Velocity?\n");

  scanf("%f", &v);



  p = fopen("projectile-t2 results.txt","w");

  printf("\nTime\t\tX Distance\tY Distance\n", t, x, y);

  fprintf(p,"\nTime\t\tX Distance\tY Distance\n", t, x, y);




 t = 0;

       do

       {



       x = vx(h, t);

       y = vy(In_h, v, t);



       if (y <= 0)

       {

       break;

       }

       printf("%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       fprintf(p,"%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       t+=0.05;

       }

       while(y > 0);



 fflush(p);

 fclose(p);





 printf("\nGoodbye from the most Advanced Projectile Motion Calculator!!\n");



return(0) ;

}


 return(h*t);

 }



float vy(float In_h, float v, float t)

 {

 return (In_h+((v*t)+(t*t)*(-9.81)));

 }



void welcome()

 {

 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");

 }



int main()

 {



  float In_h, h, v, x, y, t;

  FILE* p;





  welcome();





  printf("\nEnter Initial height:\n");

  scanf("%f", &In_h);

  printf("Enter Initial Horizontal Velocity?\n");

  scanf("%f", &h);

  printf("Enter Initial Vertical Velocity?\n");

  scanf("%f", &v);





  p = fopen("projectile-t2 results.txt","w");

  printf("\nTime\t\tX Distance\tY Distance\n", t, x, y);

  fprintf(p,"\nTime\t\tX Distance\tY Distance\n", t, x, y);





 t = 0;

       do

       {



       x = vx(h, t);

       y = vy(In_h, v, t);



       if (y <= 0)

       {

       break;

       }

       printf("%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       fprintf(p,"%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       t+=0.05;

       }

       while(y > 0);



 fflush(p);

 fclose(p);





 printf("\nGoodbye from the most Advanced Projectile Motion Calculator!!\n");



return(0) ;

}


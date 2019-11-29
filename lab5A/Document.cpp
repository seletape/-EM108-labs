/* standard C libraries */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>





int main(void)

{

 /* Declare Variables: v_ini, v, x, y, t, y_ini */

 float v_ini, v, x, y, t, y_ini;



 /* Print: "Welcome Message */

 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");



 /* Input: y_ini, v_ini, v */

 printf("\nEnter Initial height:\n");

 scanf("%f", &y_ini);

 printf("Enter Initial horizontal Velocity:\n");

 scanf("%f", &v_ini);

 printf("Enter Initial Vertical Velocity:\n");

 scanf("%f", &v);



 /* Calculate: x = v_ini*t, y = y_ini+((v*t)+(t*t)*(-9.81)) */

 printf("\nTime\t\tX Distance\tY Distance\n");

 for (t= 0; t <= 10; t)

                      {

                       x = v_ini*t ;

                       y = y_ini+((v*t)+(t*t)*(-9.81));

                       if (y <= 0)

                      {

 break;



 /* Output: x, y, t */

 }

 printf("%1.3f\t\t%3.3f\t\t%3.3f \n\n", t, x, y);

 t=t+0.05;

 }



 /* Print: "Goodbye Message" */

 printf("\nGoodbye from the most Advanced Projectile Motion Calculator!!\n");



 return(0) ;

}






/* standard C libraries */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



/* Declare Variables and Functions: welcome, vx, vy, v_ini, v, x, y, y_ini */

float vx(float v_ini, float t);

float vy(float y_ini, float v, float t);

void welcome();



float vx(float v_ini, float t)

 {

 return(v_ini*t);

 }



float vy(float y_ini, float v, float t)

 {

 return (y_ini+((v*t)+(t*t)*(-9.81)));

 }



void welcome()

 {

 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");

 }



int func ()

 {

  /* Input: y_ini, v_ini, v */

  float y_ini, v_ini, v, x, y, t;

  FILE* p;



  /* Print: "Welcome Message */

 void welcome();



  /* Input: y_ini, v_ini, v */

  printf("\nEnter Initial height:\n");

  scanf("%f", &y_ini);

  printf("Enter Initial Horizontal Velocity?\n");

  scanf("%f", &v_ini);

  printf("Enter Initial Vertical Velocity?\n");

  scanf("%f", &v);



  /* Output: x, y, t, projectile-t2 results.txt */

  p = fopen("projectile-t2 results.txt","w");

  printf("\nTime\t\tX Distance\tY Distance\n", t, x, y);

  fprintf(p,"\nTime\t\tX Distance\tY Distance\n", t, x, y);



 /* Calculate: x = v_ini*t, y = y_ini+((v*t)+(t*t)*(-9.81)) */

 t = 0;

       do

       {



       x = vx(v_ini, t);

       y = vy(y_ini, v, t);



       if (y <= 0)

       {

       break;

       }

       printf("%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       fprintf(p,"%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);

       t+=0.05;

       }

       while(y >= 0);



 fflush(p);

 fclose(p);



 /* Print: "Goodbye Message" */

 printf("\nGoodbye from tv_inie most Advanced Projectile Motion Calculator!!\n");



return(0) ;

}




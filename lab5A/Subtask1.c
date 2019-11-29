/* standard C libraries */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>





int main(void)

{



 float v_ini, v, x, y, t, y_ini;





 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");





 printf("\nEnter Initial height:\n");

 scanf("%f", &y_ini);

 printf("Enter Initial horizontal Velocity:\n");

 scanf("%f", &v_ini);

 printf("Enter Initial Vertical Velocity:\n");

 scanf("%f", &v);





 printf("\nTime\t\tX Distance\tY Distance\n");

 for (t= 0; t <= 10; t)

                      {

                       x = v_ini*t ;

                       y = y_ini+((v*t)+(t*t)*(-9.81));

                       if (y <= 0)

                      {

 break;





 }

 printf("%1.3f\t\t%3.3f\t\t%3.3f \n\n", t, x, y);

 t=t+0.05;

 }





 printf("\nGoodbye from the most Advanced Projectile Motion Calculator!!\n");



 return(0) ;

}







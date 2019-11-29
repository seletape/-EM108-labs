/* standard C libraries */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>






void cal(float y_ini, float h,  float v)
 {


 printf("\nTime\t\tX Distance\tY Distance\n");
float y, t, x;
 for (t= 0; t <= 5; t)

                      {

                       x = h*t ;

                       y = y_ini+((v*t)+(t*t)*(-9.81));

                       if (y <= 0)

                      {

 break;





 }

 printf("%1.3f\t\t%3.3f\t\t%3.3f \n\n", t, x, y);

 t=t+0.05;
                      }
 }


void goodbye()
{



 printf("\nGoodbye from the most Advanced Projectile Motion Calculator!!\n");

}

void message()
{
    printf("Press F/n");
}


int main(void)

{

 /* Declare Variables: h, v, x, y, t, y_ini */

 float h, v, y_ini;



 /* Print: "Welcome Message */

 printf("Welcome to the most Advanced Projectile Motion Calculator!\n");



 /* Input: y_ini, h, v */

 printf("\nEnter Initial Height:\n");

 scanf("%f", &y_ini);

 printf("Enter Initial Horizontal Velocity:\n");

 scanf("%f", &h);

 printf("Enter Initial Vertical Velocity:\n");

 scanf("%f", &v);

 cal( y_ini, h,  v);
 message();
 goodbye();

 return(0);
}









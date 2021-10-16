#include<stdio.h>
#include<math.h>

int main() {
int rad; float PI = 3.14;
  
printf("\nEnter radius of circle: ");
scanf("%d", &rad);
printf("\nArea of circle : %f ",  PI * pow(rad,2.0)); // formula to find area of circle

printf("\nCircumference: %f ",  2 * PI * rad); // formula for Circumference of circle
return (0);
}

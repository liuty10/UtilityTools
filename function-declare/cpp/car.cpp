#include<stdio.h>
#include"car.h"

car::car(){
   color = 0;
}

int car::print(){
   printf("car clor is: %d!\n", color);
}

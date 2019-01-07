/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/09/2017 03:30:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include<stdio.h>

void foo1(){
  char c[8];
  scanf("%s",c);
  printf("%s\n",c);
}

int main(){
  foo1();
  printf("back to main\n");
  return 0;
}


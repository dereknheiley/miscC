#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  
  *a=*b; /*this will actually allow you to access the value
	  b points to, and assign it to the value a points to */
  
  a=b; /*only changes the pointer a to be equal to the pointer 
	b, but since nothing references the pointer a or b, and they
	disappear after this function ends they don't do anything*/

  *b=temp;
}

int main(void){
  int a=4;
  int b=5;
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}

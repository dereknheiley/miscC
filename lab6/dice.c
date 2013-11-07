#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 6

int main(void) {

  //instance variables
  int throws;
  int result;
  int i;
  int array[LEN] = {0};
  srand((unsigned) time (NULL));

  printf("How many throws of the dice?: ");
  scanf("%d", &throws);
  if (throws < 0) {
    printf("Please enter a positive integer.\n");
    return main();
  }

  while (throws>0) {
    result = rand() % 6;
    array[result] = array[result]+1;
    throws--;
  }
  
  printf("Here are the results of the dice throws:\n");
  for(i=0; i<LEN; i++)
    printf("%d was thrown %d times\n", i+1, array[i]);
 
  return 0;
}

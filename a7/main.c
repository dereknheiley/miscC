#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//main program execution
int main(void){
  
	//get first line of words
	struct node *list=malloc(sizeof(struct node));
	firstline(&list);

	//count words in common on second line
	int common = secondline(&list);
  
  //end program
  printf("%d\n", common);

  return 0;
}





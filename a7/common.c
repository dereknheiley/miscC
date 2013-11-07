#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "words.h"
#include <string.h>

//store first line of distinct words in list
void firstline(struct node **listptr){
  //allocate memory for first node
	struct node *curr = malloc(sizeof(struct node));
  check(curr);
  int go=1; //loop controller
  //load words from first line into ordered linked list
  while(go){
    go=getword(curr->word, MAX_WORD_LEN);
    if(go>1){
    	if((*listptr)->word=='\0')//if list is empty
    		strcpy((*listptr)->word, curr->word);
    	else if(insert(*listptr,curr)){
    	  *listptr=curr;//move list pointer to front of list
    	  curr = malloc(sizeof(struct node));
    	  check(curr);
      }
    }
    go=go%3;
  }
  free(curr);
}

//compare words on next line with list contents
int secondline(struct node **listptr){
  int common=0;//number of words in common
  int go=1; //loop controller
  char temp[MAX_WORD_LEN]; //temp word holder
  while(go){
    go=getword(temp, MAX_WORD_LEN);
    if(go>1)
      common+=delete(listptr, temp);
    go=go%3;
  }
  return common;
}

//function to check node memory allocation
void check(struct node *node){
if (node == NULL) {
  printf("Out of memory.\n");
  exit(EXIT_FAILURE);
 }
}

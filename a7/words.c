#include <stdio.h>
#include <stdlib.h>
#include "words.h"
#include "common.h"
#include <string.h>

int insert(struct node *list, struct node *new) {
  //make sure this isn't a duplicate
  if(search(list, new->word))
    return 0;//not using this node, so reuse it next loop
  new->next = list;
  return 1; //if something was actually inserted
}

//linear search through ordered list
//return prev node for location if not found so it can be inserted?
int search(struct node* list, char *str){
  while (list != NULL){
    if(strcmp(str,list->word)==0)
	  return 1; //already in list, don't insert again
    list = list->next;
  }
  return 0; //not found,
}

int delete(struct node** listptr, char *str) {
  struct node *prev, *curr;
  for (curr=*listptr, prev=NULL;
       curr!=NULL && strcmp(str,curr->word)!=0;
       prev=curr, curr=curr->next)
    ;
  if (curr==NULL) //not found or empty list
    return 0;
  if (prev==NULL) //we're deleting the first node
    *listptr=curr->next;
  else //set curr node we're deleting's next to prev next
    prev->next=curr->next;
  free(curr); //because we're deleting the curr node
  return 1; //return that we found it
}

//words are A-Za-z characters only, stored in lower case
int getword(char word[], int len){
  int c, i=0;
  while(1){
    c=getchar();
    if(c>64 && c<91)//convert to lower
      c=c-'A'+'a';
    if(c>96 && c<123){//store
      if (i < len)
        word[i++] = c;
      else{
	printf("Word length exceeded!");
	exit(EXIT_FAILURE);
      }
    }
    else{ //it's some other symbol we don't want
      int store = i>0;
      int stop = c=='\n';
      if(store)//if there's anything to store
    	  word[i] = '\0';
      if(!store && !stop)
    	  return 1;
      if(store && !stop)
    	  return 2;
      if(store && stop)
    	  return 3;
      return 0;//!store and stop
    }
  }
  return 0;
}

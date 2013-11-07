#include <stdio.h>
#include <limits.h>
#define flights 8

int abs(int);

int main(void){

  int hour, min, total;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);
  total = hour*60 + min;

  int depTime[flights]={8*60};
  int arvTime[flights]={10*60+16};
  
  //compare total to depTime,s get index with lowest diff
  int diff=INT_MAX;
  int newdiff=INT_MAX;
  int i=0, j;
  for(j=0; j<flights; j++){
    if((newdiff=abs(depTime[j]-total))<diff){
      diff = newdiff;
      i=j;
    }
  }
  
  //return depature time
  min=depTime[i]%60;
  hour=(depTime[i]-min)/60;
  printf("Closest departure time is %d:%d p.m., ", hour, min);
  
  //return arrival time
  min=arvTime[i]%60;
  hour=(arvTime[i]-min)/60;
  printf("arriving at %d:%d p.m.\n", hour, min);

  return 0;
}

int abs(int a){
  if(a>=0)
    return a;
  else
    return -a;
}

#include <stdio.h>

int main(void) {
  
  //variables
  int i, days, start, counter=0;

  //get user input for making calendar
  printf("Enter number of days in month: ");
  scanf("%d", & days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", & start);
  
  for(i=1-start; i<=days; i++){
    counter++;
    if(i<1)
      printf("   ");
    else if(i<10)
       printf(" %d ", i);
    else
      printf("%d ", i);
    if(counter==7){
      printf("\n");
      counter=0;
    }
  }
  printf("\n");
  return 0;
}

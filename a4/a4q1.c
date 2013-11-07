#include <stdio.h>

//program to compute two second order polynomials
int main(void){

  int option =-1;
  int left1, left2, right1, right2; 

  //load all the variables
  scanf("%d %d %d %d %d", & option, & left1, & left2, & right1, & right2);
  
  if( option>=0 && option<=3 ){ //check if the operation is valid
    int result1=0, result2=0, result3=0;
    if(option==1){ //addition
      result2 = left1 + right1;
      result3 = left2 + right2;
    }
    else if(option==2){ //subtraction
      result2 = left1 - right1;
      result3 = left2 - right2;
    }
    else if(option==3){ //multiplication
      result1 = left1*right1;
      result2 = left1*right2 + left2*right1;
      result3 = left2*right2;
    }
    printf("%d %d %d\n", result1, result2, result3);
  }
  else // notify user of invalid entry
    printf("Invalid operation.\n");
  return 0;
}

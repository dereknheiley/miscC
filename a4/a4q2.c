#include <stdio.h>

//program to compute numeric root of non negative integer
int main(void){

  int x; 
  int root(int x);
  //load the input
  scanf("%d", & x);
  
  if( x>0 ){ //check if the input is valid
    int y = root(x);
    while(y>10) // compute root until anser is <= 10
      y = root(y);
    printf("%d\n", y);
  }

  else{ // notify user of invalid entry
    printf("The input number must be nonnegative.\n");
  }

  return 0;
}

//add up sum of digits in number
int root(int x){
  
  int mod = 10;
  int y = x % mod;
  while(x >= mod){
    y += (x % (mod*10) - x % mod) / mod;
    mod = mod*10; // increment mod to get next digit
  }

  return y;
}

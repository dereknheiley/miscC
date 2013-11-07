#include <stdio.h>

//main program
int main(void){
  
  //instance variables
  char letter;
  int shift=3; //not macro so it can be updated

  //get leading char to determine operation
  letter=getchar();
  if(letter=='$'){ //encrypt
    shift=shift; 
    printf("?");
  }
  else if(letter=='?'){ //decrypt
    shift=26-shift; 
    printf("$");
  }
  else{
    printf("The message must start with either $ (for encryption) or ? (for decryption)\n");
    return 1;
  } 

  //process chars
  while((letter=getchar())!='\n'){
    if(letter>='a' && letter<='z')
      letter = ((letter-'a')+shift)%26 +'a';
    else if(letter>='A' && letter<='Z')
      letter = ((letter-'A')+shift)%26 +'A';
    
    //output converted char
    printf("%c",letter);
  }

  //finish with new line
  printf("\n");
  
  return 0;
}

#include <stdio.h>
#include <ctype.h>

int main(void){

  int a[26]={0};
  char c;

  printf("Enter first word: "); 
  while((c=getchar())!= '\n'){
    c=tolower(c);
    int temp = a[c-'a'] +1;
    a[c-'a'] = temp;
  }
  
  printf("%d\n", a['t']);

  return 0;
}

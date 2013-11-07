#include <stdio.h>

int main(void) {
  //instance variables
  int n1, n2, n3, n4, n5, n6, n7, n8, n9;
  
  //get values for variables
  scanf("%d%d%d%d%d%d%d%d", & n1, & n2, & n3, & n4, & n5, & n6, & n7, & n8, & n9);

  //calculate output
  int o1 = n1*4 + n2*2 + n3;
  int o2 = n4*4 + n5*2 + n6;
  int o3 = n7*4 + n8*2 + n9;
  
  //print output
  printf("%d %d %d\n", o1, o2, o3);

  return 0;
}

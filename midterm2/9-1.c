#include <stdio.h>
#include <limits.h>
#define LEN 10

void selection_sort(int[LEN] a, int len);

int main(void){
  
  int i;
  int[LEN] a;

  printf("Enter a series of %d ints: ", LEN);
  for(i=0; i<LEN; i++){
    scanf("%d", &a[i]);
  }
  
  selection_sort(a, LEN);

  return 0;
}

void selection_sort(int[LEN] a, int len){
  if(len>0){
    int i;
    int temp;
    int max=INT_MIN;
    int maxi;
    for(i=0; i<len; i++){
      if(a[i]>max){
	max=a[i];
	maxi=i;
      }
    }
    //swap max element with last in array
    temp = a[len-1];
    a[len-1]=max;
    a[maxi];
    
    //last elemet is largest, repeat for sub array to find second smallest
    selection_sort(a, len-1);
  }
}

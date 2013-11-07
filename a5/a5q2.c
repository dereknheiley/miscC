#include <stdio.h>
#define LEN 10 //is the number of points (lines of two integers only) for input

//prototype decalrations
void mergesort(int array[][2], int lower, int upper);
void merge(int array[][2], int lower, int middle, int upper);

//main program that runs
int main(void) {

  //instance variables
  int array[LEN][2]; //holds x,y coordinate pairs
  int i; //loop counter

  //get coordinate pairs & store in array
  for (i = 0; i < LEN; i++) 
    scanf("%d %d", &array[i][0] ,&array[i][1]);

  //sort the array of coordinate pairs
  mergesort(array, 0, LEN-1);

  int maxY=array[0][1]-1;//user y from heights x value
  //subtract 1 to avoid using >= in maxY check

  //print out maximal points
  for(i=0; i<LEN; i++)
    if(array[i][1]>maxY) //then it's a maximal point so print it
      printf("%d %d\n", array[i][0], maxY=array[i][1]);

  return 0;
}

//sorts 2D array for coordinate pair by x values in decending order
void mergesort(int array[][2], int lower, int upper) {
  if (lower < upper) {
    int middle = (lower + upper) / 2; 
    mergesort(array, lower, middle);
    mergesort(array, middle+1, upper);
    merge(array, lower, middle, upper);
  }
}

void merge(int array[][2], int lower, int middle, int upper) {
  int len_left = middle - lower + 1;
  int len_right = upper - middle;
  int left[len_left][2], right[len_right][2];
  int i, j, k;

  for (i = 0; i < len_left; i++){ 
    left[i][0] = array[lower + i][0];
    left[i][1] = array[lower + i][1];
  }

  for (j = 0; j < len_right; j++){
    right[j][0] = array[middle + 1 + j][0];
    right[j][1] = array[middle + 1 + j][1];
  }

  i = 0;
  j = 0;
  k = lower;

  while (i < len_left && j < len_right) {
    if (left[i][0] >= right[j][0]) {
      array[k][0] = left[i][0];
      array[k][1] = left[i][1];
      i++;
    }
    else {
      array[k][0] = right[j][0];
      array[k][1] = right[j][1];
      j++;
    }
    k++;
  }

  while (i < len_left) {
    array[k][0] = left[i][0];
    array[k][1] = left[i][1];
    i++;
    k++;
  }

  while (j < len_right) {
    array[k][0] = right[j][0];
    array[k][1] = right[j][1];
    j++;
    k++;
  }
}


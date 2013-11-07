#include <stdio.h>

void mergesort(int array[], int lower, int upper);
void merge(int array[], int lower, int middle, int upper);

int main(void) {
  int len;

  printf("Enter the length of the array: ");
  scanf("%d", &len);

  int array[len];

  printf("Enter %d integers:\n", len);

  for (int i = 0; i < len; i++) 
    scanf("%d", &array[i]);

  mergesort(array, 0, len-1);

  printf("The sorted array is: \n");
  for (int i = 0; i < len; i++) {
    printf("%d", array[i]);
    if (i < len - 1)
      printf(" ");
  }
  printf("\n");

  return 0;
}

void mergesort(int array[], int lower, int upper) {
  if (lower < upper) {
    int middle = (lower + upper) / 2; 
    mergesort(array, lower, middle);
    mergesort(array, middle+1, upper);
    merge(array, lower, middle, upper);
  }
}

void merge(int array[], int lower, int middle, int upper) {
  int len_left = middle - lower + 1;
  int len_right = upper - middle;
  int left[len_left], right[len_right];
  int i, j, k;

  for (i = 0; i < len_left; i++) 
    left[i] = array[lower + i];

  for (j = 0; j < len_right; j++)
    right[j] = array[middle + 1 + j];

  i = 0;
  j = 0;
  k = lower;

  while (i < len_left && j < len_right) {
    if (left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    }
    else {
      array[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < len_left) {
    array[k] = left[i];
    i++;
    k++;
  }

  while (j < len_right) {
    array[k] = right[j];
    j++;
    k++;
  }
}


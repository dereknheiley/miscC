#include <stdio.h>

#define LEN 4

void swap(int array[], int i, int j);
void permute(int array[], int low, int len);

int main(void) {
  int array[LEN];
  int i;

  for (i = 0; i < LEN; i++)
    array[i] = i + 1;

  permute(array, 0, LEN);
}

void permute(int array[], int low, int len) {
  int i;

  if (_________________) {
    for (i = 0; i < len; i++)
      printf("%d ", array[i]);
    printf("\n");
  }
  else {
    for (i = low; i < len; i++) {
      swap(array, low, i);
      permute(array, _____________, len);
      swap(array, low, i);
    }
  }
}

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

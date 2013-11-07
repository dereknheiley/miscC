#include <stdio.h>

#define LEN 10

int main(void) {
  int array[LEN] = {3, 12, 21, 23, 34, 37, 52, 88, 89, 99};
  int key;
  int lower, upper, middle;

  printf("Enter a positive number to be searched for: ");
  scanf("%d", &key);
  if (key < 0) {
    printf("Please enter a positive integer.\n");
    return 1;
  }

  lower = 0;
  upper = LEN - 1;
  middle = (lower + upper) / 2;

  while (array[middle] != key && lower <= upper) {
    if (key < array[middle])
      upper = middle - 1;
    else
      lower = middle + 1;

    middle = (lower + upper) / 2;
  }

  if (array[middle] == key)
    printf("%d is at location %d.\n", key, middle+1);
  else
    printf("Not found.\n");

  return 0;
}

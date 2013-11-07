#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int size;
  printf("Enter the size of the latin square: ");
  scanf("%d", &size);

  int square[size][size];
  int i, j;

  printf("Enter a matrix (%d by %d) of integers in the range [1-%d]: \n", size, size, size);
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++) {
      scanf("%d", ______________);

      if (square[i][j] > size || square[i][j] <= 0) {
	printf("Error: element out of range.\n");
	return 1;
      }
    }

  bool visited[size];

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++)
      visited[j] = false;

    for (j = 0; j < size; j++) {
      if (visited[________________]) {
	printf("This is not a Latin square.\n");
	return 1;
      }
      else 
	visited[square[i][j]-1] = true;
    }
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++)
      visited[j] = false;

    for (j = 0; j < size; j++) {
      if (visited[_______________]) {
	printf("This is not a Latin square.\n");
	return 1;
      }
      else 
	visited[square[j][i]-1] = true;
    }
  }

  printf("This is a Latin square.\n");
  return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int i, j;
  char *key;
  for (i=2; i<argc; i++) {
    key = argv[i];
    j=i-1;
    while (j>=1 && strcmp(argv[j], key) > 0) {
      argv[j+1] = argv[j];
      j--;
    }
    argv[j+1]=key;
  }
  for (i=1; i<argc; i++)
    puts(argv[i]);
  return 0;
}

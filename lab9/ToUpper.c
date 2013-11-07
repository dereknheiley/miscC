#include <stdio.h>
#include <ctype.h>


int main(int argc, char* argv[]){

  FILE *fp;
  char ch;
  //make sure we have a filename
  if(argc!=2){
    fprintf(stderr, "Not enough arguments to open file");
    return 1;
  }
  //open file and make sure it works
  if((fp=fopen(argv[1],"r"))==NULL){
    fprintf(stderr, "Can't get read permissions opening file");
    return 1;
  }
  //get each letter from the file and check for lower case letter
  while((ch=getc(fp))!=EOF){
    if(ch>='a' && ch<='z')
      ch=toupper(ch);
    //print the char
    printf("%c", ch);
  }
  //end program
  fclose(fp);
  return 0;
}

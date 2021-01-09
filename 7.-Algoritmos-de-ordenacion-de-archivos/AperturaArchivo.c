#include<stdio.h>
 
int main()
{
  int c;
  FILE *fpReadFile;
  fpReadFile = fopen("sampleFile.txt", "wt");
  printf("\n");
  if(fpReadFile)
  {
    printf("\nReading File...\n\n");
    while ((c = getc(fpReadFile)) != EOF)
    putchar(c);
    fclose(fpReadFile);
  }
  else
  {
    printf("\nError: Unable to open the file for Reading.");
  }
  return 0;
}
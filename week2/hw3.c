#include <stdio.h>


int main(int a,char *n[]){
  if(a != 3){
    printf("wrong syntax");
  }
  FILE *fp1,*fp2;
  char A[100];
  fp1 = fopen(n[1],"a");
  fp2 = fopen(n[2],"r");
  if(fp1 == NULL){
    printf("khong ton tai");
    return 1;
  }
  if(fp2 == NULL){
    printf("khong ton tai");
    return 1;
  }
  while( fgets(A,100,fp2) != NULL){
    fputs(A,fp1);
  }
  printf("complete");
  fclose(fp1);
  fclose(fp2);
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;

int main(int n,char *m[]){
  if(n != 4){
    printf("Syntax error");
    return 1;
  }
  FILE *ptr,*fp1,*fp2;
  phone a[1];
  ptr = fopen(m[3],"w+b");
  fp1 = fopen(m[1],"r+b");
  fp2 = fopen(m[2],"r+b");
  if( ptr == NULL || fp1 == NULL || fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  while(fread(a,sizeof(phone),1,fp1) != 0){
    fwrite(a,sizeof(phone),1,ptr);
  }
  while(fread(a,sizeof(phone),1,fp2) != 0){
    fwrite(a,sizeof(phone),1,ptr);
  }
  fclose(ptr);
  fclose(fp1);
  fclose(fp2);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Phone{
  char name[25];
  char sdt[15];
}phone;

int main(){
  FILE *ptr;
  phone a[20];
  int i;

  if( (ptr = fopen("grade.dat","r+b")) == NULL){
	printf("Cannot open the file");
	return 1;
  }
  fread(a,sizeof(phone),20,ptr);
  printf("\n\n");
  printf("%-20s %-20s\n","Name","sdt");
  for(i=0;i<20;i++){
    printf("%-20s %-20s\n",a[i].name,a[i].sdt);
  }
  fclose(ptr);
  return 0;
}

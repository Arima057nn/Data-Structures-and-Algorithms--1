#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Num 20
typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;

int main(){
  FILE *ptr;
  int i;
  phone a[Num];
  
  ptr = fopen("grade.dat","w+b");
  if( ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  for(i=0;i<Num;i++){
    printf("Name[%d]: ",i+1);
    gets(a[i].name);
    printf("SDT[%d]: ",i+1);
    gets(a[i].sdt);
  }
 
  fwrite(a,sizeof(phone),Num,ptr);
  fclose(ptr);
  
  return 0;
}

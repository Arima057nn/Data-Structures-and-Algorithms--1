#include <stdio.h>
int decimal(int a){
  if(a == 1){
    return 1;
  }else{
    printf("%d",decimal(a/2));
    return a%2;
  }
}

int main(){
  int a;
  printf("Input number: ");
  scanf("%d",&a);
  printf("%d",decimal(a));
  printf("\n");
  return 1;
}

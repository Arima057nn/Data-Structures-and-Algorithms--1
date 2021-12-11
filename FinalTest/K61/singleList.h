#include <stdio.h>
#include <stdlib.h>

typedef soocer element;
typedef struct node{
  element data;
  struct node *next;
} node;

void initialize(node **root){
  *root = NULL;
}
node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->data = e;	
  new->next = NULL;
  return new;
}
void displayNode(node *p);

void traversingList(node *root){
  node *p;
  for(p=root;p!=NULL;p=p->next){
  displayNode(p);
  }

}
node *insertAtHead(element A,node **root){
  node *new = makeNewNode(A);
  if(*root==NULL){
    *root = new;
  }else{
    new->next=*root;
    *root=new;
  }
  return *root;
}
node *insertAtTail(element A,node **root){
  node *new = makeNewNode(A);
  node *p = *root;
  if(*root == NULL){
    *root = new;
  }else{
    while(p->next != NULL){
      p = p->next;
    }
    p->next = new;
  }
  return *root;//Xem lai==========================
}
/*node *insertAfterCurrent(element A,node **root){
  node *new = makeNewNode(A);
  node *prev,*cur;
  if(*root==NULL){
    insertAtHead(A,*root);
  }else if(cur==NULL){
    printf("Current is NULL\n");
    return ;
  }else{
    new->next = cur->next;
    prev = cur;
    cur->next = new;
    cur = new;
  }
}

node *insertBeforeCurrent(element A,node **root){
  node *new = makeNewNode(A,node **root);
  if(*root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  }else{
    new->next=cur;
    if(cur==root){
      root=new;
      prev=NULL;
    }else{
      prev->next=new;
    }
    cur=new;
  }
}
*/
node *insertAtPosition(element A,int n,node **root){
  node *new = makeNewNode(A);
  node *cur = *root;
  node *prev;
  int i;
  if(cur == NULL){
    *root = new;
    return *root;
  }
  if(n == 0){
    insertAtHead(A,&(*root));
    return *root;
  }
  for(i = 1; i < n ; i++){
    prev = cur;
    cur = cur->next;
    if(cur == NULL){
      printf("\nn > i vo li");
      return NULL;
    }
  }
  new->next = cur->next;
  cur->next = new;
  return *root;
}

node *delFirstElement(node **root){
  node *del = *root;
  if(del == NULL){
    printf("Error pointer");
  }else{
    *root = del->next;
    free(del);
  }
  return *root;
}

node *delLastElement(node **root){
  node *p = *root;
  if(p == NULL){
    printf("Error pointer");
  }else if((*root)->next == NULL){
    delFirstElement(&(*root));
  }else{
    while( p->next->next != NULL){
      p = p->next;
    }
      p->next = NULL;
  }
  return *root;
}
/*
/*node *delCurrentElement(){
  if(cur == NULL){
    return ;
  }
  if(cur == root){
    delFirstElement();
  }else{
    prev->next = cur->next;
    free(cur);
    cur = prev->next;

  }
}
*/
node *delAtPosition(int k,node **root){
  int i;
  node *cur;
  node *p = *root;
  if(p == NULL){
    printf("Error pointer");
    return *root;
  }
  if(k == 0){
    delFirstElement(&(*root));
    return *root;
  }
  for(i=0;i<k-1;i++){
    p = p->next;  
    if(p == NULL){
      printf("Khong ton tai");
      return *root;
    }
  }
  cur = p->next->next;
  free(p->next);
  p->next = cur;
  return *root;
  }
void freeList(node **root){
  node *fre = *root;
  while(fre != NULL){
    *root = (*root)->next;
    free(fre);
    fre = *root;
  }
}
node *list_reverse(node **root){
  node *cur = NULL, *prev = NULL;
  while(*root != NULL){
    cur = *root;
    *root = (*root)->next;
    cur->next = prev;
    prev = cur;
  }
  return prev;
}


void searching(node *root,element e){
  node *p;
  int i = 0;
  for(p = root; p!= NULL;p = p->next){
    if(compare(p->data,e) == 1){
        printf("Tim thay! \n");
        displayNode(p);
        i = 1;
        return;
    }
  }
  if(i == 0)  printf("Khong tim thay");
  return;
}
void swap(node **a,node **b){
  element temp;
  temp = (*a)->data;
  (*a)->data = (*b)->data;
  (*b)->data = temp;
}

void sortList(node **root){
  node *p1,*p2;
  for(p1 = *root ; p1 != NULL; p1 = p1->next){
    for(p2 = p1->next ; p2 != NULL ; p2 = p2->next){;
      if(compare(p1->data,p2->data) == 1){
	swap(&p1,&p2);
      }
    } 
  }
}


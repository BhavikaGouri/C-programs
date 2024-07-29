#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *tail;

void append() {
    
    struct node *temp,*p;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &temp -> data);
    temp -> right = NULL;
    temp -> left = NULL;
    
    if(tail == NULL) {
        tail = temp;
        tail -> right = tail;
        tail -> left = tail;
        p = tail;
    }
    
    else {
        temp -> right = tail -> right;
        tail -> right = temp;
        temp -> left = tail;
        tail = tail -> right;
        p -> left = temp;
    }
}

void display() {
    
    struct node *p;
    p = tail -> right;
    do {
        printf("%d ", p -> data);
        p = p -> right;
    }while(p != tail -> right);
}

int main() {
    int n;
    printf("the number of nodes you want : ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        append();
    }
    display();
    
    return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

void push() {
    
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &temp -> data);
    
    temp -> link = top;
    top = temp;
    
}

void pop() {
    
    if(top == NULL) {
        printf("underflow");
    }
    else {
        struct node *p;
        p = top;
        printf("the data popped is : %d \n", p -> data);
        top = top -> link;
        p -> link = NULL;
        free(p);
    }
}

void display(struct node *p) {
    while(p != NULL) {
        printf("%d", p -> data);
        p = p -> link;
    }
}

int main() {
    
    push();
    push();
    push();
    pop();
    push();
    display(top);
    
    return 0;
}
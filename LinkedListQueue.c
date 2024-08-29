#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *rear = NULL;
struct node *front = NULL;

void enque() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &temp -> data);
    temp -> link = NULL;
    
    if(rear == NULL && front == NULL) {
        rear = temp;
        front = temp;
    }
    
    else {
        rear -> link = temp;
        rear = rear -> link;
    }
}

void deque() {
    
    if(front == NULL) {
        printf("underflow");
    }
    else {
    struct node *p = front;
    printf("\n%d is node data deleted \n", p -> data);
    front = front -> link;
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
    int n;
    printf("enter number of nodes : ");
    scanf("%d", &n);
    for(int i = 0; i< n; i++) {
        enque();
    }
    display(front);
    deque();
    display(front);
    
    return 0;
}


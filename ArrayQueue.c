#include<stdio.h>
#define size 10

int front = -1;
int rear = -1;

int A[size];

void enque() {
    
    if(rear == size -1) {
        printf("overflow");
    }
    
    else if(front == -1 && rear == -1) {
        front++;
        rear++;
        printf("enter data : ");
        scanf("%d", &A[rear]);
    }
    
    else {
        rear++;
        printf("enter data : ");
        scanf("%d", &A[rear]);
    }
    
}

void deque() {
    
    if(front == -1) {
        printf("underflow");
    }
    
    else if(front == size - 1) {
        printf("the data removed is %d\n", A[front]);
        front = -1;
    }
    
    else {
        printf("the data removed is %d\n", A[front]);
        front++;
    }
}

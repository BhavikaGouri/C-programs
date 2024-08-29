#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d", &temp -> data);
    temp -> link = NULL;
    
    if(front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
        rear -> link = rear;
    }
    else {
        temp -> link = rear -> link;
        rear -> link = temp;
        rear = rear -> link;
    }
}

void display(struct node *p) {
   p = p -> link;
   do{
       printf("%d", p -> data);
       p = p -> link;
   }while(p -> link != front -> link);
}

int main() {
   
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++) {
        enqueue();
    }
    
    display(rear);
    return 0;
}





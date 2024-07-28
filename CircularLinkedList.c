#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *tail = NULL;

void append() {
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &temp -> data);
    temp -> link = NULL;
    
    if(tail == NULL) {
        tail = temp;
        tail -> link = tail;
    }

    else {
        temp -> link = tail -> link;
        tail -> link = temp;
        tail = tail -> link;
    }
}

void display(struct node *p) {
    p = p -> link;
    do {
        printf("%d", p -> data);
        p = p -> link;
    }while(p != tail -> link);
}


int main() {
    int m;
    
    printf("enter the number of nodes you want : ");
    scanf("%d", &m);
    
    for(int i = 0; i < m ; i++) {
        append();
    }
    
    display(tail);
    
    return 0;
}

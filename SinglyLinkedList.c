#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *link;
};
struct node *root;


void append() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL) {
        root = temp;
    }
    else {
        struct node *p;
        p = root;
        while(p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
}


void display() {
    struct node *s;
    s = root;
    while(s!=NULL) {
        printf("%d->%p\n",s->data,s->link);
        s = s->link;
    }
}


int length(){
    int cnt = 0;
    struct node *k;
    k = root;
    while(k != NULL) {
        cnt +=1;
        k = k->link;
    }
    return cnt;
}


void delete(){
    
    int n ,i = 1,j = 1;
    printf("enter the postion after the node is to be deleted ");
    scanf("%d", &n);
    if(n<0) {
        printf("invalid\n");
    }
    else if(n==0){
        struct node *k;
        k = root;
        root = root->link;
        free(k);
    }
    else if(n >= length()) {
        printf("Invalid\n");
    }
    else{
    struct node *k,*q;
    k = root;
    q = root;
    
    while(i < n){
        k = k->link;
        i++;
    }
    while(j < n+1){
        q = q-> link;
        j++;
    }
    k -> link = q->link;
    q ->link = NULL;
    
    free(q);
}}

void insert() {
    int a,i=1;
    printf("enter positon after you want to insert ");
    scanf("%d", &a);
    if(a == length()){
        append();
    }
    else if(a == 0) {
        struct node *k;
        k =(struct node*) malloc(sizeof(struct node));
        printf("enter data ");
        scanf("%d",&k -> data);
        k -> link = root;
        root = k;
    }
    else if(a > length()){
        printf("invalid");
    }
    else{
        
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("enter data ");
        scanf("%d", &temp ->data);
        temp -> link = NULL;
        struct node *l;
        l = root;
        while(i != a){
            l = l -> link;
            i++;
        }
        temp -> link = l -> link;
        l -> link = temp;
        
    }
}

// reverse using recursion
void reverseA(struct node *p) {
    struct node *q;
    
    if(p -> link == NULL) {
        root = p;
        return;
    }
    reverseA(p -> link);
    q = p-> link;
    q -> link = p;
    p -> link = NULL;
    
}


// reverse using iteration
void reverseB(){
    struct node *p,*q,*n;
    p = NULL;
    q = root;
    n = root;
    while(n != NULL){
        n = n -> link;
        q -> link = p;
        p = q;
        q = n;
    }
    root = p;
}


int main() {
    
    int j;
    printf("no of nodes you want ");
    scanf("%d", &j);
    for(int i =0;i<j;i++) {
        append();
    }
    printf("\nThe initial liked list: \n");
    display();
    printf("\nThe reversed linked List is: \n");
    reverseA(root);
    display();

    return 0;
    
}

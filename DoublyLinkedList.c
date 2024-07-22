#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *right,*left;
};
struct node *root;

void append() {
    
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&temp -> data);
    temp -> left = NULL;
    temp -> right = NULL;
    
    if(root == NULL) {
        root = temp;
    }
    else {
        struct node *p;
        p = root;
        while(p -> right != NULL) {
            p = p -> right;
        }
        p -> right = temp;
        temp -> left = p;
    }
}

void display() {
    struct node *p;
    p = root;
    while(p != NULL) {
        printf("%d\n", p -> data);
        p = p -> right;
    }
}

int length() {
    struct node*k;
    k = root;
    int cnt = 0;
    while(k != NULL) {
        cnt += 1;
        k = k -> right;
    }
    return cnt;
    
}

void reverse() {
    struct node *q;
    q = root;
    while( q -> right != NULL) {
        q = q -> right;
    }
    while( q != NULL) {
        printf("%d\n",q->data);
        q = q-> left;
    }
}

void insert() {
    
    int m;
    printf("enter position after which you want to insert :");
    scanf("%d", &m);
    
    if(m > length()) {
        printf("position is too high");
    }
    
    else if(m == length()) {
        append();
    }
    
    else if(m == 0) {
        
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        printf(" enter data ");
        scanf("%d", & temp -> data);
        temp -> right = NULL;
        temp -> right = root;
        root -> left = temp;
        root = temp;
    }
    
    else {
        int i = 1;
        struct node * temp;
        temp = (struct node*) malloc(sizeof(struct node));
        printf("enter data ");
        scanf("%d", & temp-> data);
        temp -> right = NULL;
        temp -> left = NULL;
        struct node *k;
        k = root;
        
        while(i != m) {
            k = k -> right;
            i++;
        }
        
        temp -> right = k -> right;
        temp -> left = (k -> right) -> left;
        (k -> right )-> left = temp;
        k -> right = temp;
        
    }
    
    
}


void delete() {
    
    int d;
    printf("enter postion which you want to delete :");
    scanf("%d", &d); 
    
    if( d > length() ) {
        printf(" position is too high ");
    }
    
    else if( d == 1 ){
        struct node *p;
        p = root;
        root = p -> right;
        root -> left = NULL;
        p -> right = NULL;
        free(p);
    }
    
    else if(1 < d < length()) {
        struct node *p,*q;
        p = root;
        
        int i = 1;
        
        while(i < d - 1) {
            p = p -> right;
            i++;
        }
        q = p -> right;
        
        p -> right = q -> right;
        (q -> right )-> left = q -> left;
        q -> right = NULL, q -> left = NULL;
        free(q);
    }
    
    else {
        printf(" not possible ");
    }
}
 


int main() {
    int n;
    printf("the number of nodes you want: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        append();
    }
    printf("the list data are:\n");
    display();
    printf("\nreversed list is :\n");
    reverse();
    printf("\nthe length of the list is :");
    printf("%d\n", length());
    insert();
    display();
    delete();
    display();
    
    return 0;
}


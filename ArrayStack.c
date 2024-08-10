#include <stdio.h>
#include <stdlib.h>
#define size 10

int top = -1;
int stack[size];

void push() {
    int a;
    printf("enter data :");
    scanf("%d", &a);
    if(top == size -1) {
        printf("overflow\n");
    }
    else {
        top = top + 1;
        stack[top] = a;
    }
}

int peek() {
    if(top != -1) 
        return stack[top];
    return 0;
    
}

void pop() {
    int a;
    if(top == -1) {
        printf("underflow\n");
    }
    else {
        a = stack[top];
        printf("%d is the element deleted\n", a);
        top = top - 1; 
    }
}

void display() {
    int j = top;
    for(int i = j; i > -1;i--) {
        printf(" %d ",stack[i]);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n\n");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1:
                push();
                display();
                break;
            
            case 2:
                pop();
                display();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                exit(0);
            
            default:
                printf("invalid");
                break;
        }
    }
    
    return 0;
}


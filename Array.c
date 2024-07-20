#include<stdio.h>

// function declarartion

int insert(int*,int, int,int);
int delete(int*,int,int);
void reverse(int *, int);

void display(int *arr, int len) {
    for(int i = 0;i < len; i++) {
        printf("%d ",arr[i]);
    }
}

int main() {
    
    int len = 10;
    int A[20];
   
    for(int i = 0; i< 10; i++) {
        printf("enter data : ");
        scanf("%d", &A[i]);
    }

    
    display(A,len);
    
    printf("\n");
    reverse(A,len);
    
    
    
    return 0;
}

int insert(int *arr, int pos, int item, int len) {
    for(int i = len; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = item;
    len = len + 1;
    return len;
}

int delete(int *arr, int pos, int len) {
    for(int i = pos; i < len - 1; i++) {
        arr[pos] = arr[pos + 1];
    }
    len = len - 1;
    return len;
}

void reverse(int *arr, int len) {
    
    int j = len - 1;
    
    int temp;
    
    for(int i = 0; i< len/2;i++) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
     display(arr,len);
}


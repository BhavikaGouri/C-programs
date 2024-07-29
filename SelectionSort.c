#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr,int n) {
    int min = 0;
    for(int i = 0; i< n-1;i++) {
        min = i;
        for(int j = i+1;j < n;j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(&arr[min],&arr[i]);
        }
    }
}

int main() {
    int *A,n;
    A = (int *) malloc(sizeof(int));
    printf("enter number of elements : ");
    scanf("%d",&n);
    for(int i = 0; i< n;i++) {
        printf("enter data :");
        scanf("%d",&A[i]);
    }
    
    sort(A,n);
    
    for(int i = 0; i< n;i++) {
        printf(" %d ",A[i]);
    }
    
    return 0;
}
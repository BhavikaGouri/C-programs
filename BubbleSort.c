#include<stdio.h>

void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int len) 
{
    for(int j = 0; j < len - 1; j ++) {
        for(int i = 0; i < len - 2; i++) {
            if(arr[i] > arr[i+1]) 
            {
                swap(&arr[i],&arr[i+1]);
            }
        }
    }
}

void display(int *arr, int len) {
    for(int i = 0; i< len; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int A[] = {2,5,1,4,3,7,0,9};
    int len = 8;
    sort(A, len);
    display(A,len);
    
    return 0;
}

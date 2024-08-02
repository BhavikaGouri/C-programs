#include <stdio.h>
#include<stdlib.h>
int main()
{
    int *A;
    int n,key,j;
    printf("enter number of elements : ");
    scanf("%d", &n);
    A = (int *)malloc(n*sizeof(int));
    for(int i = 0;i < n; i++) {
        printf("enter data : ");
        scanf("%d", &A[i]);
    }
    
    for(int i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while(j >= 0 && key < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    
    for(int k = 0; k < n;k++) {
        printf("%d ", A[k]);
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#define N 12

int A[N] = {4,2,8,5,9,1,6,3};

void insertion_sort(int A[], int l, int r){
    int key, j, i=l;
    for(j=i+1; j<=r; ++j){
        key = A[j];
        i = j-1;
        while(i>=l && A[i]>key)
            A[i+1] = A[i--]; 
        A[i+1] = key;
    }
}

int main(void)
{
    insertion_sort(A, 0, 1);
    for (int i = 0; i < 10; ++i)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}


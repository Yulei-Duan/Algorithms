#include <stdio.h>  
#define N 1000
#define INF 0x7fffffff // 无穷大

int L[N/2];
int R[N/2];

void Merge(int* A,int p,int q,int r);
void Merge_Sort(int *A,int p,int r) 
{ 
    if(p >= r) return;
    int q=(p+r)/2; 
    Merge_Sort(A,p,q); 
    Merge_Sort(A,q+1,r); 
    Merge(A,p,q,r); 
} 

void Merge(int* A,int p,int q,int r) 
{ 
    int n1= q-p+1; 
    int n2= r-q; 
     
    // int *L= new int[n1+1]; 
    // int *R= new int[n2+1];
    
    int i=0; 
    int j=0; 
 
    for(i=0;i<n1;i++) L[i]=A[p+i]; 
    for(j=0;j<n2;j++) R[j]=A[q+j+1]; 

    L[n1] = R[n2] = INF;
    i = j = 0; 

    int k;
    for(k=p; k<=r; k++){ 
        if(L[i]<=R[j])  A[k] = L[i++]; 
        else            A[k] = R[j++];  
    } 
}  
 
int A[15] = {11,12,13,14,15,1,2,3,4,5,6,7,8,9,10};  
 
int main(void) 
{ 
    Merge_Sort(A,0,14); 
     
    for(int i=0;i<15;i++) 
    { 
        printf("%d\t", A[i]);
    } 
    printf("\n");
    return 0; 
}
#include <stdio.h>

int A[100];
int heapsize;

void swap(int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void huifu(int i){
    int maxheap = i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l <= heapsize && A[l] > A[maxheap])
        maxheap = l;
    if(r <= heapsize && A[r] > A[maxheap])
        maxheap = r;
    if(i != maxheap){
        swap(maxheap, i);
        huifu(maxheap);
    }
}    


void sort(){
    while(heapsize>1) {
        swap(heapsize, 1);
        --heapsize;
        huifu(1);
    }
}

void insert(int x){
    int i;
    A[++heapsize] = x;
    i = heapsize;
    while(i > 1 && A[i] > A[i/2]) {
        swap(i, i/2);
        i >>= 1;
    }
    /*
    while(A[heapsize] > i && i>=0){
        i/=2;
        swap(A[heapsize], A[i]);
    }*/
}

int  max(){
    return A[1];
}

int extract_max(){
    int tmp = A[1];
    A[1] = A[heapsize--];
    huifu(1);
    return tmp;
}

void build(){
    int i;
    for(i=heapsize/2; i>0 ;--i){
        huifu(i);
    }
}

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    heapsize = n;
    for(i=1;i<=n;++i){
        scanf("%d", &A[i]);
    }
    build();
    sort();
    // insert(24);
    // insert(20);
    // insert(100);
    for(i = 1; i <= n; i++)
        printf("%d\n", A[i]);
    return 0;
}
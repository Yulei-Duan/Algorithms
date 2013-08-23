#include <stdio.h>
#define N 250002
int a[N];
//dd 版 1308！
void quick_sort(int *a, int f, int t){
	int i = f;
	int j = t;
	int k = a[f];
	if(i >= j) return;
	while(i<j){
		while(i<j && a[j]>=k)
			j--;
		if(i<j)	a[i++] = a[j];
		while(i<j && a[i]<=k)
			i++;
		if(i<j) a[j--] = a[i]
	}
	a[i] = k;
	quick_sort(a,f,i-1);
	quick_sort(a,i+1,t);
}

//zsx 版 1312!
void quickSort(int *a, int l,int r){
    int k = a[l]; 
    int i = l;
    int j = r;
    while( i < j ){
        while( a[j] >= k && i < j ) j--;
        a[i] = a[j];
        while( a[i] <= k && i < j ) i++;
        a[j] = a[i];
    }
    a[j] = k;
    if(l < i-1) quickSort(a, l, i-1 );
    if(i+1 < r) quickSort(a, i+1, r );
}
//Me 
void quickSort(int *a, int l,int r){
    int k = a[l]; 
    int i = l;
    int j = r;
    if(i>=j) return;
    while( i < j ){
        while( a[j] >= k && i < j ) j--;
        a[i] = a[j];
        while( a[i] <= k && i < j ) i++;
        a[j] = a[i];
    }
    a[j] = k;
    quickSort(a, l, i-1 );
    quickSort(a, i+1, r );
}

int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0;i<n;i++)
            scanf("%d", &a[i]);
        quickSort(a, 0, n-1);
        for( i=0; i<n-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[i]);
    }
    return 0;
}
 
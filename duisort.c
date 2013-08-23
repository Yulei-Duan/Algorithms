#include <stdio.h>
#define N 250002
int a[N];
int n, heapsize;
void swap(int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void heapify(int i) {
    int largest = i;
    int l = 2 * i;
    int r = l + 1;
    if(l <= heapsize && a[l] > a[largest])
        largest = l;
    if(r <= heapsize && a[r] > a[largest])
        largest = r;
    if(largest != i) {
        swap(largest, i);
        heapify(largest);
    }
}

void build() {
    int i;
    for(i = heapsize / 2; i > 0; i--)
        heapify(i);
}

void heapSort() {
    int i;
    for(i = 1; i < n; i++) {
        swap(1, heapsize);
        heapsize--;
        heapify(1);
    }
}
 
int main()
{
	int t;
	scanf("%d",&t);
 
	while(t--)
	{
		scanf("%d",&n);
 
		int i;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		heapsize = n;
		build();
		heapSort();

		for(i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
 

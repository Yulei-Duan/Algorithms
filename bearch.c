#include <stdio.h>
int A[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
};
int bsearch(int *A, int x, int y, int v){
	int m;
	while(x<y){
		m = x+(y-x)/2;
		if(A[m] == v) return m;
		else if(A[m] > v) y = m;
		else 			  x = m+1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int i, c;
	c = bsearch(A, 0, 14, 11);
	printf("%d\n" ,c);
	printf("%d\n", A[c]);
	printf("%d\n", A[10]);

	return 0;
}
#include <stdio.h>
#include <math.h>

int isprime(int num){
	int i, j;
	j = sqrt(num);
	for(i=2;i<=j;++i)
		if(num%i == 0)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	int n, c;
	scanf("%d", &n);
	for(int i=2;i<=n;++i)
		if(isprime(i))
			printf("%8d", i);
		printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000000
#define yes '1'
#define no '0'
char flag[N];
int T = 0;
int p[80000];
int A[N];
void is_prime(){
	int i, j;
	memset(flag, yes, sizeof(flag));
	flag[0] = flag[1] = no;
	int len = sqrt(N) + 1;//N too small will be error
	for(i=2;i<len;++i){
		if(flag[i]==no) continue;
		for(j=i+i;j<=N;j+=i)
			flag[j]=no;
	}
	for(i=2;i<=N;++i)
		if(flag[i]==yes){
			T++;
			p[T] = i;
			A[i] = 1;
		}

}
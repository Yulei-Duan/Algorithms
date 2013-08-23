#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1000000
int edg[MAXN];
long long to[MAXN];
int next[MAXN];
char B[10];
int k;
 
 
int main()
{
	int t, n, i, j, L;
	long long x;
	int flag;
	scanf("%d", &t);
	while(t--){
 
		//memset(next,-1,sizeof(next));
		//memset(to,0,sizeof(to));
		scanf("%d", &n);
		memset(edg,-1, n*sizeof(int));
		k = 0;
		for(j=0;j<n;++j){
			scanf("%s", B);
 
			if(strcmp(B, "Add") == 0){
 
				scanf("%lld", &x);
				++k;
				L= abs(x) % n;
				to[k] = x;
				next[k] = edg[L];
				edg[L] = k;
 
				continue;
			}
			if(strcmp(B,"Ask") == 0){
				int tmp;
				flag = 0;
				scanf("%lld", &x);
				L= abs(x) % n;
				tmp = edg[L];
				while( tmp!=-1 ){
					if(to[tmp]==x){ printf("YES\n"); flag = 1; break;}
					tmp = next[tmp];
				}
				if(flag == 0) printf("NO\n");
				continue;
 
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX INT_MAX
#define N	100

int map[N][N];
int len[N];
int vis[N];
int n;

void build() {

	int i, j;
	int u, v, c;
	int m; 
	
	scanf("%d", &n);
	memset(map, -1, sizeof(map));
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &u, &v, &c);
		map[u][v] = c;
	}

//	scanf("%d", &s);
}

void dij() {

	int min;
	int i, t;

	memset(vis, 0, sizeof(vis));
	for(i = 0; i <= n; i++)
		len[i] = MAX;
	len[0] = 0;

	while(1) {
		min = n;
		for(i = 0; i < n; i++){
			if(vis[i]) continue;
			if(len[i] < len[min])
				min = i;
		}

		if(min == n) break;
		printf("min = %d\n", min);
		vis[min] = 1;

		for(i = 0; i < n; i++) {
			if(vis[i] || map[min][i] == -1) continue;
			t = len[min] + map[min][i];
			if(len[i] > t)
				len[i] = t;
 		}
	}

}

void show() {

	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%-5d", map[i][j]);
		printf("\n");
	}
	printf("\n\n");

	for(i = 0; i < n; i++)
		printf("%d, ", len[i]);
	printf("\n\n");
}


int main(int argc, char const *argv[])
{
	freopen("duan","r",stdin);
	build();
	dij();
	show();

	return 0;
}
/*
6 8
0 5 5
0 2 10
0 4 30
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
*/






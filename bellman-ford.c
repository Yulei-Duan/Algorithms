#include <stdio.h>
#include <limits.h>
#define MAX		INT_MAX 

int n, m;
int s[100], e[100], l[100];
int dis[100];

void input() {
	int i;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
		scanf("%d%d%d", &s[i], &e[i], &l[i]);
}

int bellman_ford() {
	int i, j;
	for(i = 0; i < n; i++)
		dis[i] = MAX;
	dis[0] = 0; //0 is the start point

	int u, v;
	for(i = 1; i < n; i++) {
		for( j = 0; j < m; j++) {
			u = s[j], v = e[j];
			if(dis[u] < MAX && dis[v] > dis[u] + l[j])
				dis[v] = dis[u] + l[j];
		}
	}

	for(j = 0; j < m; j++) {
		u = s[j], v = e[j];
		if(dis[v] < dis[u] + l[j])
			return 0;
	}
	return 1;
}

void show() {
	int i;
	for(i = 0; i < n; i++)
		printf("%-5d ", dis[i]);
	printf("\n\n");
}

int main() {
	input();
	bellman_ford();
	show();
	return 0;
}

/*
6 8
0 5 100
0 2 10
0 4 30
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60

*/
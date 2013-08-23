#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX		INT_MAX 

int n, m;
int map[100][100];
int dis[100];
int in[100];
int time[100];

void input() {
	int i;
	int u, v, l;
	scanf("%d%d", &n, &m);
	memset(map, -1, sizeof(map));
	for(i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &l);
		map[u][v] = l;
	}
}

int spfa() {
	int i;
	int stack[100], top;

	memset(in, 0, sizeof(in));
	memset(time, 0, sizeof(time));
	for(i = 0; i < n; i++)
		dis[i] = MAX;

	dis[0] = 0;
	time[0] = 1;
	in[0] = 1;

	top = 0;
	stack[top++] = 0;

	while(top > 0) {
		int u = stack[--top];
		in[u] = 0;
		for(i = 0; i < n; i++) {
			if(map[u][i] != -1 && dis[u] + map[u][i] < dis[i]) {
				dis[i] = dis[u] + map[u][i];
				if(in[i] == 1) continue;
				in[i] = 1;
				time[i]++;
				if(time[i] == n) return 0;
			}
		}
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
	spfa();
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
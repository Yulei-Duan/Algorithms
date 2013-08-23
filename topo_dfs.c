#include <stdio.h>
#define N 100

int map[N][N], vis[N], stack[N];
int n, m, k;

void build() {
    int u, v;
    memset(map, 0, sizeof(map));

    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &u, &v);
        map[u][v] = 1;
    }
}

void dfs(int s) {
    int i;

    vis[s] = 1;
    for(i = 0; i < n; i++) {
        if(!vis[i] && map[s][i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    //printf("%5d", s);
    stack[k++] = s;
}

void topo() {
    int i;

    k = 0;
    memset(vis, 0, sizeof(vis));
    for(i = 0; i < n; i++) {
        if(!vis[i])
            dfs(i);
    }

    for(i = n-1; i > -1; --i)
        printf("%5d", stack[i]);
    printf("\n");
}

int main() {
    build();
    topo();
    return 0;
}

/**
9 9

0 1
0 4
1 2
1 4
2 7
3 4
5 6
5 2
6 7
*/

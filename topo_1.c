#include <stdio.h>
#include <string.h>
#define N 100

int map[N][N], deg[N], vis[N];
int n, m;
void build() {
    int u, v;
    memset(map, 0, sizeof(map));
    memset(deg, 0, sizeof(deg));

    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &u, &v);
        map[u][v] = 1;
        deg[v]++;
    }
}

void topo() {
    int i, node;

    memset(vis, 0, sizeof(vis));
    while(1) {
        for(i = 0; i < n; i++) {
            if(!vis[i] && deg[i] == 0) {
                node = i;
                break;
            }
        }
        if(i == n)
            break;
        vis[i] = 1;
        printf("%5d", node);
        for(i = 0; i < n; i++) {
            if(map[node][i])
                deg[i]--;
        }
    }
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

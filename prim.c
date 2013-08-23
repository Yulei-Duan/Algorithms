#include <stdio.h>
#include <string.h>
#define N 100

int map[100][100];
int dis[N], vis[N], p[N];
int m, n;

void build() {
    int u, v, c;
    scanf("%d%d", &n, &m);
    memset(map, -1, sizeof(map));
    while(m--) {
        scanf("%d%d%d", &u, &v, &c);
        map[u][v] = map[v][u] = c;
    }
}

int mst() {
    int i, min, sum = 0;
    memset(dis, 127, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(p, -1, sizeof(p));

    dis[0] = 0;

    while(1) {
        min = n;
        for(i = 0; i < n; i++) {
            if(!vis[i] && dis[i] < dis[min])
                min = i;
        }

        if(min == n)
            return sum;
        vis[min] = 1;
        if(p[min] != -1)
            printf("<%c, %c>\n", p[min]+'a', min+'a');

        sum += dis[min];

        for(i = 0; i < n; i++) {
            if(!vis[i] && map[min][i] != -1 && dis[i] > map[min][i]) {
                dis[i] = map[min][i];
                p[i] = min;
            }
        }
    }
    return sum;
}

void show() {

}

int main() {
    build();
    printf("%d\n", mst());
    show();
    return 0;
}

/**
9 14
0 1 4
0 7 8

1 2 8
1 7 11

2 3 7
2 5 4
2 8 2

3 4 9
3 5 14

4 5 10

5 6 2

6 8 6
6 7 1

7 8 7
*/











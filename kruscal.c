#include <stdio.h>
#include <string.h>
#define N 1000

int n, m;
int s[N], e[N], l[N];
int p[N];

void qsort(int f, int t) {
    if(f >= t)
        return;
    int i = f, j = t;
    int ll = l[f], ss = s[f], ee = e[f];

    while(i < j) {
        while(i < j && ll <= l[j])
            j--;
        if(i < j) {
            l[i] = l[j]; s[i] = s[j]; e[i] = e[j];
            i++;
        }
        while(i < j && ll >= l[i])
            i++;
        if(i < j) {
            l[j] = l[i]; s[j] = s[i]; e[j] = e[i];
            j--;
        }
    }

    l[i] = ll; s[i] = ss; e[i] = ee;
    qsort(f, i-1);
    qsort(i+1, t);
}

int root(int i) {
    while(i != p[i])
        i = p[i];
    return i;
}

void link(int a, int b) {
    p[root(a)] = p[root(b)];
}

void build() {
    int i;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++) {
        scanf("%d%d%d", &s[i], &e[i], &l[i]);
    }
}

void show() {
    int i;
    for(i = 0; i < m; i++)
        printf("<%d, %d> = %d\n", s[i], e[i], l[i]);
}

int kruscal() {
    qsort(0, m-1);
    ///show();

    int i, sum = 0, edge = 0;

    for(i = 0; i < n; i++)
        p[i] = i;

    for(i = 0; i < m; i++) {
        if(root(s[i]) == root(e[i]))
            continue;
        link(s[i], e[i]);
        printf("<%c, %c>\n", s[i]+'a', e[i]+'a');
        sum += l[i];
        edge++;
        if(edge == n-1)
            return sum;
    }
}

int main() {
    build();
    printf("%d\n", kruscal());
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

#include <stdio.h>
#include <string.h>
#define N 40
int queue[N*N][2];
char map[N][N];
int flag[N][N];
int sx, sy;
 
void find(int n){
	int i, j;
	for (i = 1; i <= n; ++i)
	{
 
		for(j=1;j<=n;++j)
			if(map[i][j] == 'S'){
				sx = i;
				sy = j;
			}
	}
}

int BFS(int n){
	find(n);
 
	memset(flag, -1, sizeof(flag));
	int movex[]= {0, 0, 1, -1};
	int movey[]= {1, -1, 0, 0};
 
	int head , tail;
	head = tail = 0;
 
	queue[tail][0] = sx;
	queue[tail++][1] = sy;
	flag[sx][sy] = 1;
 
	int x, y;
	while(head != tail){
 
		x = queue[head][0];
		y = queue[head++][1];
 
 
		int i;
		int cx , cy;
 
		for(i = 0;i<4;i++){
			cx = x + movex[i];
			cy = y + movey[i];
 
 
			if(flag[cx][cy] == -1){
				if(map[cx][cy] == '.'){
					queue[tail][0] = cx;
					queue[tail++][1] = cy;
					flag[cx][cy] = flag[x][y] + 1;
				}
				else if(map[cx][cy] == 'E')
					return flag[x][y] ;
 
			}
		}
	}
 
	return -1;
}
 
int main()
{
	int t, n, i;
	scanf("%d", &t);
	while(t--){
 
		scanf("%d", &n);
		memset(map, '*', sizeof(map));
		for(i=1;i<=n;++i)
			scanf("%s",&map[i][1]);
		printf("%d\n",BFS(n));
 
	}
 
	return 0;
}
#include <stdio.h>
#include <queue>
using namespace std;
 
 
int map[20][20];
int nb,nw;
int n,b,w;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
 
struct  Node
{
    int x,y;
}p,k;
 
 
void   bfs(int x,int y)
{
    int num=0;
    queue<Node> q;
    p.x=x;
    p.y=y;
    q.push(p);
    map[x][y]=3;
    int flag1=0,flag2=0;
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        num++;
        for(int i=0;i<4;i++)
        {
            p.x=k.x+d[i][0];
            p.y=k.y+d[i][1];
            if(p.x>=1&&p.x<=n&&p.y>=1&&p.y<=n)
            {
                if(map[p.x][p.y]==0)
                {
                    q.push(p);
                    map[p.x][p.y]=3;
                }
                else if(map[p.x][p.y]==1)
                    flag1=1;
                else if(map[p.x][p.y]==2)
                    flag2=1;
            }
        }
    }
    if(flag1+flag2!=2)
    {
        if(flag1)
            nb+=num;
        if(flag2)
            nw+=num;
    }
}
 
 
int main()
{
    int x,y;
    int i,j;
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%d%d",&b,&w);
        memset(map,0,sizeof(map));
        for( i=1;i<=b;i++)
        {
            scanf("%d%d",&x,&y);    //black
            map[x][y]=1;
        }
        for( i=1;i<=w;i++)
        {
            scanf("%d%d",&x,&y);    //white
            map[x][y]=2;
        }
        nb=nw=0;
        for( i=1;i<=n;i++)
          for( j=1;j<=n;j++)
            if(!map[i][j])
                bfs(i,j);
       if(nb==nw)
           printf("Draw\n");
       else if(nb-nw>0)
           printf("Black wins by %d\n",nb-nw);
       else if(nw-nb>0)
           printf("White wins by %d\n",nw-nb);
 
    }
  return 0;
}
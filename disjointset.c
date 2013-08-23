#include <stdio.h>
#include <string.h>
#define MAX 1000

int p[MAX];
int rank[MAX];
void init(int n){
    int i;
//    memset(rank, 0, sizeof(rank));
    for(i=1;i<n;i++) {p[i]=i;rank[i]=0;}
}


int find_root_digui(int x){
    if(x!=p[x])
        return p[x]=find_root(p[x]);
    else return x;
} 

int find_root(int x){
    
    int i=x;
    while(i!=p[i])
        i=p[i];
    int rot=i;
    int temp;
    i=x;
    while (i!=p[i]){
        temp=i;
        i=p[i];
        p[temp]=rot;
    }
    return rot;
}

int conn(int x,int y){
    x=find_root(x);
    y=find_root(y);
    return x==y;
}

void _union(int x,int y){
    x=find_root(x);
    y=find_root(y);

    if(rank[x]>=rank[y])
        p[y]=x;
    else p[x]=y;
    
    if(rank[x]==rank[y]) rank[x]++;
}
    
void try() 
{
    _union(1,2);
    _union(3,4);
    _union(2,4);
    _union(5,6);
    _union(7,8);
    _union(6,8);
    _union(2,6);
    int root = find_root(8);
    printf("root = %d\n", root);
    
    for(int i=1; i<10; i++)
    {
        printf("p[%d]=%d, rank[%d]=%d\n", i, p[i], i, rank[i]);
    }
    
    while(1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", conn(a,b));
        printf("%d\n",rank[1]);
        printf("%d\n",find_root(1));
    }
    
}

int main(){
    int n=20;
    init(n);
    try();
    return 0;
}
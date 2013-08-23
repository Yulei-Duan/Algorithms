#include <stdio.h>
int vis[9], a[9];
void dfs(int s, int n) {
    int i;
    if(s == n) {
        for(i = 0; i < n; i++)
			if(i==0) printf("%d", a[i]);
	        else     printf(" %d", a[i]);
        printf("\n");
        return;
    }
    for(i = 1; i <= n; i++) {
        if(vis[i]) continue;
        a[s] = i;
        vis[i] = 1;
        dfs(s+1, n);
        vis[i] = 0;
    }
}
int main() {
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
	    dfs(0, n);
	}
	return 0;	
}
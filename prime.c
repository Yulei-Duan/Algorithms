#include <stdio.h>
#include <string.h>
#include <math.h>

#define N   100000
#define yes '1'
#define no  '0'
char flag[N+1];

void is_prime(int n)
{
    int i, j;
    memset(flag, yes, sizeof(flag));
    flag[0]=flag[1]=no;
    int len=sqrt(n)+1;
    for(i=2; i<len; i++)
    {
        if(flag[i]==no) continue;
        for(j=i+i; j<=n; j+=i)
            flag[j]=no;
    }
}

int main(void)
{
    int n;
    ///find the primes from 1 to n(n<=N)
    scanf("%d", &n);
    is_prime(n);
    for(int i=1; i<=n; i++)
        if(flag[i]==yes)
            printf("%8d", i);
    printf("\n");
    return 0;
}

/*
用于大数据，数据很小的话就用第一种吧

 1　　建立一个全1的数组(下标2~N),

 2　　先将下标是2的倍数的全置0，再将下标是3的倍数全置0,……，以此类推，

 3　　最后剩下的，仍是1的那些下标，就肯定是素数了。
*/
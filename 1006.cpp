#include<iostream>
#include<stdio.h>
using namespace std;

# define INF 105

int main()
{
    int n,x;
	scanf("%d",&n);
    int minSum = INF,curSum = 0,ans=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        curSum += x;
        ans = max(ans, curSum-minSum);
        minSum = min(minSum, curSum-x);
    }

    if (ans > 0) printf("%d\n",ans);
    else printf("Game Over\n");

    return 0;
}
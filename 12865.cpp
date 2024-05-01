#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[104][200004];

int main() 
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        int w,v;
        scanf("%d %d",&w,&v);
        dp[i+1][w] = v;
        for (int j=1; j<=k; j++) {
            if(dp[i][j]) {
                dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
                dp[i+1][j+w] = max(dp[i][j+w],dp[i][j]+v);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=k; i++) ans = max(dp[n][i],ans);
    printf("%d",ans);
}
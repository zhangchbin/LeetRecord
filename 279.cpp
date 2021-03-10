class Solution {
public:
    int numSquares(int n) {
        int a[110];
        for(int i=0;i<=100;i++) a[i] = i*i;

        int dp[10010];
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = 0x3f3f3f3f;
            for(int j=1;j<=100;j++){
                if(a[j] > i) continue;
                dp[i] = min(dp[i - a[j]] + 1, dp[i]);
            }

        }

        return dp[n];
    }
};

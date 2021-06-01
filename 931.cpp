class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int dp[110][110];
        int n = matrix.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = 0x3f3f3f3f;
        
        for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j+1<=n-1) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                if(j-1>=0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                dp[i][j] = min(dp[i-1][j], dp[i][j]) + matrix[i][j];
            }
        }
        int ans = 0x3f3f3f3f;
        for(int j=0;j<n;j++) ans=min(ans, dp[n-1][j]);
        return ans;
    }
};

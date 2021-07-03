class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0 || word2.size() == 0) return max(word1.size(), word2.size()); 
        int dp[1010][1010];
        memset(dp, 0, sizeof(dp));
        int n=word1.size(), m=word2.size();
        dp[0][0] = (word1[0] != word2[0]);
        for(int i=1; i<n; i++) dp[i][0] = min(i + (word1[i] != word2[0]), dp[i-1][0]+1);
        for(int j=1;j<m; j++) dp[0][j] = min(j + (word1[0] != word2[j]), dp[0][j-1]+1);

        for(int i=1; i<n; i++){
            for(int j=1;j<m;j++){
                if(word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
            }
        }
        int ans = 0x3f3f3f3f;
      
        return dp[n-1][m-1];
    }
};

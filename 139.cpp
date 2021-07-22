class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int dp[100100];
        memset(dp, 0, sizeof(dp));
        map<string, int> ma;
        int n = s.size();

        for(int i=0;i<wordDict.size();i++) ma[wordDict[i]] = 1;

        for(int i=0; i<n;i++){
                for(int j=0;j<=i;j++){
                    int exsit = ma[s.substr(j, i+1-j)];
                    if(j==0) dp[i] = dp[i] | exsit;
                    else dp[i] = dp[i] | (exsit & dp[j-1]);
                }
        }
        return dp[s.size()-1];
    }
};

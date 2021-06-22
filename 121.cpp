class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval[100100];
        minval[0] = prices[0];
        for(int i=1;i<prices.size();i++)
            minval[i] = min(minval[i-1], prices[i]);
        int ans=0;
        for(int i=0;i<prices.size();i++)
            ans = max(ans, prices[i] - minval[i]);
        return ans;
    }
};

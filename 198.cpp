class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[10010];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        if(nums.size()>=1) dp[0] = nums[0];
        if(nums.size()>=2) dp[1] = nums[1];
        if(nums.size()>=3) dp[2] = nums[2] + nums[0];
        for(int i=3;i<nums.size();i++) dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        for(int i=0;i<nums.size();i++) ans = max(ans, dp[i]);
        return ans;
    }
};

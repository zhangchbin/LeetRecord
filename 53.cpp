class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long dp[30010];
        dp[0] = nums[0];
        for(int i=1; i < nums.size(); i++){
            if(dp[i-1] > 0) dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
        }
        long long ans = -0x3f3f3f3f;
        for(int i=0;i<nums.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[3000];
        dp[0] = -0x3f3f3f3f;
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            int pos = lower_bound(dp, dp+cur+1, nums[i]) - dp;
            if(pos <= cur){
                dp[pos] = nums[i];
            }
            else{
                cur++;
                dp[cur] = nums[i];
            }
        }
        return cur;

    }
};

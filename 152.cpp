class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv = 1;
        int minv = 1;
        int ans = -0x3f3f3f3f;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) swap(maxv, minv);
            maxv = max(maxv * nums[i], nums[i]);
            minv = min(minv * nums[i], nums[i]);
            ans = max(ans, maxv);
        }
        return ans;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxval = nums[0];
        
        for(int i=1; i < nums.size(); i++){
            if(maxval >= i) maxval = max(maxval, nums[i] + i);
        }
        return maxval >= nums.size()-1;
    }
};

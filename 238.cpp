class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre[100100];
        int last[100100];
        pre[0] = nums[0];
        last[nums.size()-1] = nums[nums.size()-1];
        vector<int>ans;
        int n = nums.size();
        for(int i=1;i<nums.size();i++) pre[i] = pre[i-1] * nums[i];
        for(int i=n-2;i>=0;i--) last[i] = last[i+1] * nums[i];
        for(int i=0;i<n; i++){
            if(i==0) ans.push_back(last[i+1]);
            else if(i==nums.size()-1) ans.push_back(pre[i-1]);
            else ans.push_back(pre[i-1]*last[i+1]);
        }
           
        return ans;
    }
};

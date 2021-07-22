class Solution {
public:
    long long hash(vector<int>& pp){
        return pp[0] * 100000LL + pp[1];
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int dp[200100];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++) dp[nums[i]+100000] = 1;
        map<long long, int> ma;

        for(int i=0;i<n-2;i++){
            if(nums[i] > 0) continue;
            for(int j=i+1;j<n-1;j++){
                int sum = nums[i] + nums[j];
                if(sum > 0) continue;
                if(-sum > nums[n-1]) continue;
                if(-sum < nums[j+1]) continue;
                int idx = -sum + 100000;
                if(dp[idx]&&-sum>=nums[j]){
                    vector<int>tmp = vector<int>{nums[i], nums[j], -sum};
                    if(ma[hash(tmp)] == 0)
                        ans.push_back(tmp),
                        ma[hash(tmp)] = 1;
                    else continue; 
                } 
                //int pose = *lower_bound(nums.begin() + j+1, nums.end(), -sum);
                //if(pose+sum == 0) ans.push_back(vector<int>{nums[i], nums[j], pose});
            }
        }
        //sort(ans.begin(), ans.end());
        //ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

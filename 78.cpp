class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int>a;
            ans.push_back(a);
            int x = i;
            int j=0;
            
            while(x){
                if(x&1) ans[i].push_back(nums[j]);
                x>>=1;
                j++;
            }
        }
        return ans;
    }
};

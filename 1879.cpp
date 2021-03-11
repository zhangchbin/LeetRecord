class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int val=0;
        for(int i=0;i<nums.size();i++){
            val ^= nums[i];
        }
        int p=1;
        while(!(val & 1)){
            p<<=1;
            val>>=1;
        }
        int a=0, b=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&p)) a^=nums[i];
            else b^=nums[i];
        }
        return vector<int>{a,b};
    }
};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int dp_ins[10010], dp_des[10010];
        memset(dp_ins, 0, sizeof(dp_ins));
        memset(dp_des, 0, sizeof(dp_des));
        for(int i = 1; i < A.size(); i++){
            if(A[i] > A[i-1]) dp_ins[i] = dp_ins[i-1] + 1;
        }
        for(int i = A.size()-2; i >=0; i--){
            if(A[i] > A[i+1]) dp_des[i] = dp_des[i+1] + 1;
        }
        int ans = 0;
        for(int i=0;i < A.size(); i++){
            if(dp_ins[i] == 0 || dp_des[i] == 0)
                continue;
            ans = max(ans, dp_ins[i] + dp_des[i] + 1);
        }
        return ans;
    }
};

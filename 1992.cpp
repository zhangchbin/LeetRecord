class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l=0,r=0;
        vector<int>L, R;
        for(int i = 0; i < height.size(); i++){
            L.push_back(max(l, height[i]));
            l = L[L.size()-1];
        }
        for(int i = height.size()-1; i>=0;i--){
            R.push_back(max(r,height[i]));
            r=R[R.size()-1];
        }
        reverse(R.begin(), R.end());
        for(int i=0;i<height.size();i++){
            ans += min(L[i], R[i]) - height[i];
        }
        return ans;

    }
};

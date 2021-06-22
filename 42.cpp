class Solution {
public:
    int trap(vector<int>& height) {
        int lmax[30010];
        int rmax[30010];
        int n = height.size();
        if(n==0) return 0;
        lmax[0] = 0;
        rmax[n-1] = 0;
        for(int i=1;i<n;i++)
            lmax[i] = max(lmax[i-1], height[i-1]);
        for(int i=n-2;i>=0;i--)
            rmax[i] = max(rmax[i+1], height[i+1]);
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += max(0, min(lmax[i], rmax[i])-height[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1;
        int mid;
        int ans = citations.size();
        while(l <= r){
            mid=(l+r)/2;
            if(citations[mid]<(citations.size()-mid)){
                l = mid+1;
            }
            else r = mid-1, ans=mid;
        }
        return citations.size()-ans;


    }
};

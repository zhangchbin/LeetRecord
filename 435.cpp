class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int> > a;
        for(int i=0;i<intervals.size();i++){
            a.push_back(pair<int,int>{intervals[i][1], intervals[i][0]});
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int rp = 0x3f3f3f3f;
        rp = -rp;
        for(int i=0;i<a.size();i++){
            if(a[i].second < rp) continue;
            ans++;
            rp = a[i].first;
        }
        return a.size() - ans;
    }
};

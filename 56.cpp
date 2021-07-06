class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]) return a[1] < b[1];
        else return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > ans;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i=1; i<intervals.size();i++){
            int tmpl = intervals[i][0];
            int tmpr = intervals[i][1];
            if(tmpl > r){
                vector<int>a;
                a.push_back(l);
                a.push_back(r);
                ans.push_back(a);
                l = tmpl, r = tmpr;
            }
            else{
                r = max(r, tmpr);
            }
        }
        vector<int>a;
        a.push_back(l);
        a.push_back(r);
        ans.push_back(a);
        return ans;
    }
};

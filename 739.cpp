class Solution {
public:
    int binary_search(vector<int>& tmp, int val){
        if(tmp.size()==0) return 0;
        int l=0, r=tmp.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(tmp[mid]<=val){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        if(tmp[r]<=val) return 0;
        else return tmp[r];
    }

    vector<int> dailyTemperatures(vector<int>& T) {
        vector<vector<int> > a;
        for(int i=0;i<101;i++) a.push_back(vector<int>{});
        for(int i=0;i<T.size();i++){
            a[T[i]].push_back(i);
        }
        vector<int>ans;
        for(int i = 0; i < T.size(); i++){
            int tmp=60000;
            for(int j=T[i]+1;j<=100;j++){
                int kk = binary_search(a[j], i);
                if(kk) tmp = min(tmp, kk);
            }
            if(tmp<60000) ans.push_back(tmp-i);
            else ans.push_back(0);
        }
        
        return ans;

    }
};

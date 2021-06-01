class Solution {
public:
    int str2int(string tmp){
        int val = 0;
        int ex=1;
        for(int i=tmp.length()-1; i>=0;i--){
            if(tmp[i]=='1') val += ex;
            ex <<= 1;
        }
        return val;
    }
    bool hasAllCodes(string s, int k) {
        map<int, int>ma;
        int n = s.length();
        for(int i=0;i+k<=n;i++){
            string substr = s.substr(i, k);
            int val = str2int(substr);
            ma[val] = 1;
        }
        return ma.size() == (1<<k);
    }
};

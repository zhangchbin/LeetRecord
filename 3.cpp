class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int l = 0;
        map<char, int>pos;
        pos[s[0]] = 0;

        map<char, int>cnt;
        cnt[s[0]]++;

        for(int i=1; i < s.length(); i++){
            if(cnt[s[i]]){
                for(int j = l; j <= pos[s[i]]; j++){
                    cnt[s[j]]--;
                }
                l = pos[s[i]] + 1;
            }
            pos[s[i]] = i;
            cnt[s[i]]++;
            ans = max(ans, i - l + 1);
        }
        if(s.length() == 0) ans = 0;
        return ans;
    }
};

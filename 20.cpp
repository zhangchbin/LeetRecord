class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        int ans = 1;
        sta.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] ==']'){
                if(sta.empty()==false && s[i] == ')' && sta.top() == '(') sta.pop();
                else if(sta.empty()==false && s[i] == ']' && sta.top() == '[')  sta.pop();
                else if(sta.empty()==false && s[i] == '}' && sta.top() == '{') sta.pop();
                else {
                    ans = 0;
                    break;
                }
            }
            else{
                sta.push(s[i]);
            }
        }
        ans = (ans && (sta.empty() == true));
        if(ans) return true;
        else return false;
    }
};

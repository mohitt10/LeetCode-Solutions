class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') c++;
            if(s[i] == ')') {
                if(c == 0) {
                    s.erase(i, 1);
                    n--; i--;
                    continue;
                }
                c--;
            }
        }
        c = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')') c++;
            if(s[i] == '(') {
                if(c == 0) {
                    s.erase(i, 1);
                    n--;
                    continue;
                }
                c--;
            }
        }
        return s;
    }
};
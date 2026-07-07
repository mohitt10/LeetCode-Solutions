class Solution {
public:


    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size(), curr = 0;
        for(int i = n - 1; i >= 0; i--) {
            curr = (curr + shifts[i]) % 26;
            char k = s[i] - 'a';
            s[i] = 'a' + (k + curr) % 26;
        }
        return s;
    }
};
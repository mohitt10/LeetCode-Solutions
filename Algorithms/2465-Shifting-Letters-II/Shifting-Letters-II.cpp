class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shif(n + 1, 0);
        int curr = 0;
        for(auto i: shifts) {
            int k = 0;
            if(i[2]) k = 1;
            else k = -1;
            shif[i[0]] += k;
            shif[i[1] + 1] -= k;
        }
        for(int i = 0; i < n; i++) {
            curr = (curr + shif[i]) % 26;
            int dig = (s[i] - 'a');
            s[i] = 'a' + ((dig + curr) + 26) % 26;
        }
        return s;        
    }
};
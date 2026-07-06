class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> present(n, true);
        int yes = n, curr = 0;
        while(yes > 1) {
            int c = 0;
            while(c < k) {
                if(present[curr]) c++;
                if(c == k) break;
                curr = (curr + 1) % n;
            }
            present[curr] = false; yes--;
            if(!present[curr]) {
                curr = (curr + 1) % n;
            }
        }
        for(int i = 0; i < n; i++) {
            if(present[i]) {
                return i + 1;
            }
        }
        return 0;
    }
};
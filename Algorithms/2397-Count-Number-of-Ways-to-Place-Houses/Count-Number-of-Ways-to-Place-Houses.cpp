class Solution {
public:
    int countHousePlacements(int n) {
        int MOD = 1e9 + 7;
        int prev1 = 2, prev2 = 1;
        for(int i = 2; i <= n; i++) {
           int temp = (prev1 + prev2) % MOD;
           prev2 = prev1;
           prev1 = temp;
        }   
        return (1LL * prev1 * prev1) % MOD; 
    }
};
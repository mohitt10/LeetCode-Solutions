class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int TwoOdd = nums1.size() % 2, OneOdd = nums2.size() % 2;
        int ans = 0;
        if(TwoOdd) {
            for(auto i: nums2) ans ^= i;
        }
        if(OneOdd) {
            for(auto i: nums1) ans ^= i;
        }
        return ans;
    }
};
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long s = 0;
        string ss;
        while(n) {
            int d = n % 10;
            s += d;
            char j = d + '0';
            if(d != 0) ss = j + ss;
            n /= 10;
        }
        if(ss == "") return 0;
        return stoll(ss) * s;
    }
};
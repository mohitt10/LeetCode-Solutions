class Solution {
public:
    long long sumAndMultiply(int n) {
        long long s = 0, num = 0;
        int dig = 0;
        while(n) {
            int d = n % 10; 
            s += d;
            if(d != 0) {
                num = d * pow(10, dig) + num;
                dig++;
            }
            n /= 10;
        }
        return s * num;
    }
};
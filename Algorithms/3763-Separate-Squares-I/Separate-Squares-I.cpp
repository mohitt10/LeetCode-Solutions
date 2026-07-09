class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double m = 0;
        double l = INT_MAX, r = INT_MIN;
        for(auto sq : squares) {
            l = min(l, (double)sq[1]);
            r = max(r, (double)sq[1] + (double)sq[2]);
        }
        while((r - l) > 1e-5) {
            m = (r - l) / 2 + l;
            double LeftS = 0, RightS = 0;
            for(auto &sq : squares) {
                double y = sq[1], l = sq[2];
                if(m > y) {
                    if(m > y + l) LeftS += l * l;
                    else {
                        LeftS += l * (m - y);
                        RightS += l * (y + l - m);
                    }
                }
                else {
                    RightS += l * l;
                }
            }
            if(LeftS >= RightS) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return m;
    }
};
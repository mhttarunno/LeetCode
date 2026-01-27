class Solution {
public:
    double myPow(double base, int n) {
        long long exp = n;
        double res = 1.0;
        if (exp < 0) {
            base = 1 / base;
            exp = -exp;
        }

        while (exp) {
            if (exp & 1) {
                res = res * base;
                exp--;
            } else {
                base = base * base;
                exp /= 2;
            }
        }
        return res;
    }
};

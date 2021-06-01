class Solution {
public:
    double fastpow(double x, long long n){
        double ans = 1;
        double tmp = x;
        while(n){
            if(n&1) ans *= tmp;
            n>>=1;
            tmp*=tmp; 
        }
        return ans;
    }

    double myPow(double x, long long n) {
        if(n>=0) return fastpow(x, n);
        else return double(1.0) / (double)fastpow(x, -n);
    }
};

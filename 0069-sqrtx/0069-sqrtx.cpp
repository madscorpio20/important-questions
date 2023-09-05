class Solution {
public:
    int mySqrt(int x) {
        if(x <2)
            return x;
        int s = 1;
        long long e = x/2;
        while(s<e){
            long long mid = (s+e)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x){
                s = mid+1;
            }
            else
                e = mid-1;
        }
        if(e*e > x)
            return e-1;
        return e;
    }
};
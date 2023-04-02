class Solution {
public:
    int minOperations(int n) {
        
        if(n == 1) return 0;
        if(n%2 == 0)
        {
            n/=2;
            double k = n;
            return k/2*(2 + (k-1)*2);
        }
        else
        {
            n/=2;
            double k = n;
            return k/2*(4 + (k-1)*2);
            
        }
    }
};
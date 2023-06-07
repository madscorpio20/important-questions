class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a >=1 || b>=1 || c>=1)
        {
            if((a%2 || b%2) != c%2)
            {
                if(a%2 == 1 && b%2 == 1)
                    cnt++;
                cnt++;
            }
            a/=2;
            b/=2;
            c/=2;
        }
        return cnt;
    }
};
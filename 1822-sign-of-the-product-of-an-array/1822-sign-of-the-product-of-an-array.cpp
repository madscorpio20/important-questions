class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntNegative = 0;
        for(auto it : nums)
        {
            if(it == 0)
                return 0;
            if(it < 0)
                cntNegative++;
        }
        if(cntNegative%2 == 0)
            return 1;
        else
            return -1;
    }
};
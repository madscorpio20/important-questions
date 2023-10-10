class Solution {
    long long mod = 1e9 + 7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32,0);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<32; j++){
                if((nums[i]>>j) & 1){
                    bits[j]++;
                }
            }
        }
        long long res = 0;
        while(k > 0){
            long long curr = 0;
            for(int i=0; i<32; i++){
                if(bits[i] > 0){
                    curr += (long long)pow(2,(double)i)%mod;
                    curr = curr%mod;
                    bits[i]--;
                }
            }
            res += (curr*curr)%mod;
            res = res%mod;
            k--;
        }
        return res;
    }
};
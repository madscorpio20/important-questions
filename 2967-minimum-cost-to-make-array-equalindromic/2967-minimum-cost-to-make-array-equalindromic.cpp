class Solution {
public:
    bool checkPalindrome(int n){
        string s = to_string(n);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long median;
        if(n%2!= 0){
            median = nums[n/2];
        }else{
            median = (nums[n/2 - 1] + nums[n/2])/2;
        }

        long long ans,ans2;
        for(long long i=0; i<1e8; i++){
            if(checkPalindrome(median + i)){
                ans = 0;
                for(int j=0; j<n; j++){
                    ans += (long long) abs(median + i - nums[j]);
                }
                break;
            }
        }
        for(long long i=0; i<1e8; i++){
            if(checkPalindrome(median - i)){
                ans2 = 0;
                for(int j=0; j<n; j++){
                    ans2 += (long long) abs(median - i - nums[j]);
                }
                break;
            }
                
        }
        if(ans < ans2) return ans;
        return ans2;
    }
};
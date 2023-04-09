class Solution {
public:
    bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
  //suppose n=7 that is prime and its pair are (1,7)
  //so if a no. is prime then it can be check by numbers smaller than square root
  // of the n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> v (1e7,-1);
        for(int i=0; i<n; i++)
        {
            if(v[nums[i][i]] == -1)
            {
                if(isPrime(nums[i][i]))
                {
                    ans = max(ans,nums[i][i]);
                    v[nums[i][i]] = 1;
                }
                else
                    v[nums[i][i]] = 0;
            }
            if(v[nums[i][n-i-1]] == -1)
            {
                if(isPrime(nums[i][n-i-1]))
                {
                    ans = max(ans,nums[i][n-i-1]);
                    v[nums[i][n-i-1]] = 1;
                }
                else
                    v[nums[i][n-i-1]] = 0;
            }
            
        }
        return ans;
    }
};
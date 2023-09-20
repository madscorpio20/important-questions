class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if(x == nums[0] || x == nums[n-1]) return 1;
        map<int,int> suffix;
        int mini = 1e9;
        int curr = 0;
        for(int i=n-1; i>=0; i--){
            curr += nums[i];
            suffix[curr] = i;
            if(curr == x){
                mini = n-i;
            }
        }
        curr = 0;
        for(int i=0; i<nums.size(); i++){
            curr = curr + nums[i];
            if(curr == x){
                mini = min(mini, i+1);
            }
            if(suffix[x- curr]){
                int j = suffix[x- curr];
                if(j<=i) continue; 
                mini = min(i+1+n-j,mini);
            }
        }
        if(mini == 1e9) return -1;
        return mini;
    }
};
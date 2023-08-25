class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int k = nums[i];
            if(k >= n){
                k-=n;
            }
            if(nums[k] >= n)
                return k;
            else
                nums[k] += n;
        }
        return -1;
    }
};
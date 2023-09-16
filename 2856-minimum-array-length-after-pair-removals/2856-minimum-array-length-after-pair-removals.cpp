class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        int next;
        int cnt = 0;
        if(n%2 == 0){
            next = n/2;
        }else{
            next = (n/2) + 1;
        }
        while(ind < n/2){
            if(nums[ind] == nums[next])
                cnt++;
            ind++;
            next++;
        }
        return n%2 == 0 ? cnt*2 : cnt*2 + 1;
    }
};
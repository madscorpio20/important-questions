class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        if(nums.size() == 2){
            swap(nums[0],nums[1]);
            return;
        }
        for(int i = nums.size()-2; i>=0; i--){
            int next_num = INT_MAX;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] >  nums[i]){
                    if(next_num = INT_MAX){
                        next_num = j;
                    }
                    else
                    {
                        if(nums[j] < nums[next_num]){
                            next_num = j;
                        }
                    }
                }
            }
            if(next_num != INT_MAX){
                swap(nums[i], nums[next_num]);
                sort(nums.begin() + i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};
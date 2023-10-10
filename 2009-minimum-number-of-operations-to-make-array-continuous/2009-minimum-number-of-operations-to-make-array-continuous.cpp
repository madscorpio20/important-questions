class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int cnt = 1;
        while(s < nums.size() && nums[0] == nums[s]) s++;
        int e = s;
        s = s-1;
        int res = nums.size()-1;
        while(e < nums.size()){
            
            if(nums[e] - nums[s] + 1 <= nums.size()){
                int curr = nums[e];
                cnt++;
                res = min(res, (int)(nums.size()-cnt));
                while(e< nums.size() && nums[e] == curr){
                    e++;
                }
            }else{
                int curr = nums[s];
                cnt--;
                while(nums[s] == curr)s++;
            }
            // cout<<s<<" "<<e<<" "<<cnt<<endl;
        }
        // cout<<endl;
        return res;
    }
};
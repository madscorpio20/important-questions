class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;
        vector<int> ans;
        while(s<e){
            if(nums[s] + nums[e] == target){
                if(nums[s] == nums[e]){
                    ans.push_back(m[nums[s]][0]);
                    ans.push_back(m[nums[s]][1]);
                }
                else{
                    ans.push_back(m[nums[s]][0]);
                    ans.push_back(m[nums[e]][0]);
                }
                return ans;
                
            } 
            else if(nums[s] + nums[e] < target){
                s++;
            }
            else
                e--;
        }
        return ans;
    }
};
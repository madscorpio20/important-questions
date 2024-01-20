class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            int setbit = 0;
            int curr = nums[i];
            while(curr){
                if((curr & 1) == 1)
                    setbit++;
                curr = curr>>1;
            }
            mp[nums[i]] = setbit;
        }
        
        for(int i=0; i<nums.size(); i++){
            
            int ind = i;
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j] < nums[ind]){
                    ind = j;
                }
            }
            if(ind == i) continue;
            for(int j=ind; j>i; j--){
                if(mp[nums[j]] != mp[nums[j-1]]) return false;
                swap(nums[j], nums[j-1]);
            }
        }
        return true;
    }
};
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> perms = nums;
        sort(perms.begin(),perms.end());
        int smallest = perms[0];
        int i = 0;
        while(i < nums.size() && perms[i] == smallest)
        {
            i++;
        }
        int cnt = 0;
        int j=0;
        for(;i<perms.size(); i++)
        {
            
            if(i == j)
                break;
            if(perms[i] > perms[j])
            {
                cnt++;
                j++;
            }
            
        }
        return cnt;
        
    }
};
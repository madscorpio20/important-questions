class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = -1;
        int cnt = 0;
        for(auto it: nums){
            if(element == -1)
            {
                element = it;
                cnt = 1;
            }
            else if(it != element){
                cnt--;
                if(cnt == 0){
                    element = -1;
                }
            }
            else
                cnt++;
        }
        return element;
    }
};
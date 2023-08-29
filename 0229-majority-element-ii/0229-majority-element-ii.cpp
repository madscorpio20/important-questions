class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = -1;
        int element2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){

            if(element1 == -1 && (element2 ==-1 || nums[element2] != nums[i])){
                element1 = i;
                cnt1 = 1;
            }
            
            else if(element1 != -1 && nums[i] == nums[element1]){
                cnt1++;
            }
            else if(element2 == -1){
                element2 = i;
                cnt2 = 1;
            }
            
            else if(nums[i] == nums[element2]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
                if(cnt1 == 0)
                    element1 = -1;
                if(cnt2 == 0)
                    element2 = -1;
            }
        }
        cout<<element1<<endl;
        cout<<element2<<endl;
        cnt1 = 0;
        cnt2 = 0;
        bool e1 = false;
        bool e2 = false;
        if(element1!=-1)
        {
            e1 = true;
            element1 = nums[element1];
        }
        
        if(element2!=-1)
        {
            e2 = true;
            element2 = nums[element2];
        }
        for(int i=0; i<n; i++){
            if(e1 && nums[i] == element1)
                cnt1++;
            else if(e2 && nums[i] == element2){
                cnt2++;
            }
        }
        // cout<<cnt1<<endl;
        vector<int> ans;
        if(cnt1> n/3)
            ans.push_back(element1);
        if(cnt2 > n/3)
            ans.push_back(element2);
        return ans;
    }
};
class Solution {
public:
    vector<int> mergeSort(vector<int> &nums, int s, int e)
    {
        vector<int> ans;
        if(s>e)
            return ans;
        if(s == e)
        {
            ans.push_back(nums[s]);
            return ans;
        }
        int mid= (s+e)/2;
        vector<int> first = mergeSort(nums,s,mid);
        vector<int> second = mergeSort(nums,mid+1,e);
        int i = 0,j=0;
        while(i<first.size() && j<second.size())
        {
            if(first[i] <= second[j])
            {
                ans.push_back(first[i]);
                i++;
            }
            else
            {
                ans.push_back(second[j]);
                j++;
            }
        }
        while(i<first.size())
        {
            ans.push_back(first[i]);
            i++;
        }
        while(j<second.size())
        {
            ans.push_back(second[j]);
            j++;
        }
        return ans;
        
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
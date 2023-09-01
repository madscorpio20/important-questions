class Solution {
public:
    
    int helper(vector<int> &nums,int s, int e){
        // cout<<s<<" "<<e<<endl;
        if(s>=e)
            return 0;
        int mid = (s+e)/2;
        int ans = helper(nums,s,mid);
        ans += helper(nums, mid+1, e);
        
        
        int i = s;
        int j = mid+1;
        
        while(i<=mid){
            long long k = (long long)nums[j]*2;
            if(j <=e && k < nums[i]){
                j++;
            }
            else{
                ans += j-mid-1;
                i++;
            }
        }
        i = s;
        j = mid+1;
        vector<int> v;
        while(i <= mid && j <=e){
            if(nums[i] <= nums[j]){
                v.push_back(nums[i]);
                i++;
            }
            else
            {
                v.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            v.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            v.push_back(nums[j]);
            j++;
        }
        for(int ind=s,k=0; ind<=e; ind++,k++){
            nums[ind] = v[k];
        }
        // cout<<s<<" "<<e<<" "<<ans<<endl;
        return ans;
        
    }
    int reversePairs(vector<int>& nums) {
        map<int,vector<int>> m;
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};
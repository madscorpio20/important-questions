class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=i+1; j<nums1.size(); j++){
                int diff = 1e9;
                bool flag = true;
                int ind = 0;
                for(int k=0; k<nums1.size(); k++){
                    if(k!=i && k!=j){
                        if(diff == 1e9){
                            diff = nums2[0] - nums1[k];
                        }else{
                            if(nums2[ind] - nums1[k] != diff){
                                flag = false;
                                break;
                            }
                            
                        }
                        ind++;
                    }
                }
                if(flag){
                    return diff;
                }
            }
        }
        return 1000;
    }
};
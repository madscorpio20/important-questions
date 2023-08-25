class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2;
        if((m+n)%2!=0)
            gap++;
        for(int i=0, j = m; i<n; i++,j++){
            nums1[j] = nums2[i];
        }
        while(gap!=1 ){
            for(int i = 0, j = gap; j<m+n;i++, j++){
                if(nums1[i]> nums1[j])
                   swap(nums1[i],nums1[j]);
            }
            if(gap%2 !=0)
                gap = (gap/2) + 1;
            else
                gap = gap/2;
            
        }
        for(int i = 0, j = gap; j<m+n;i++,j++){
                if(nums1[i]> nums1[j])
                    swap(nums1[i],nums1[j]);
            }
        
    }
};
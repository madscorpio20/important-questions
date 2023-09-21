class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> v;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size())
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size())
        {
            v.push_back(nums2[j]);
            j++;
        }
        int total = nums1.size() + nums2.size();
        if(total%2 == 0)
        {
            return (v[total/2-1] + v[total/2])/2;
        }
        else
        return v[total/2];
    }
};
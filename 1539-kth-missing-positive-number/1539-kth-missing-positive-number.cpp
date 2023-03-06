class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        for(int i=0; i<arr.size();)
        {
            if(arr[i]!=num)
            {
                k--;
                if(k == 0)
                    return num;
            }
            else
                i++;
            num++;
        }
        return arr[arr.size()-1] + k;
    }
};
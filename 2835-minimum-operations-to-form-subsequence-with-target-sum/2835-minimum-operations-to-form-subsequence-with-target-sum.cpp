class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<int> v(31,0);
        for(int i=0; i<nums.size(); i++){
            int ind  = log2(nums[i]);
            v[ind]++;
        }
        vector<int> input(31,0);
        
        long i;
        int ind = 30;
        for (i = 1 << 30; i > 0; i = i / 2)
        {
          if((target & i) != 0)
          {
            input[ind] = 1;
          }
          else
          {
            input[ind] = 0;
          }
            ind--;
        }
        // if(nums[nums.size()-1] < target)
        // {
        //     long long total = 0;
        //     for(int i=0; )
        // }
        int notInd = -1;
        int ans = 0;
        long long sum = 0;
        for(int i=0; i<31; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<31; i++){
            cout<<input[i]<<" ";
        }
        cout<<endl;
        
        for(int i=0; i<31; i++){
            // cout<<sum<<endl;

            if(input[i] > v[i] && notInd == -1){
                // cout<<sum<<" "<<i<<endl;
                if(sum >= pow(2,i)){
                    sum -= pow(2,i);
                    continue;
                }
                notInd = i;
            }
            else if(v[i] > input[i] && notInd == -1){
                sum += pow(2,i)*(v[i]-input[i]);
            }
            else if(v[i] > input[i] && notInd!=-1){
                ans += i - notInd;
                sum+= pow(2,i)*(v[i]);
                if(input[i] > 0)
                    sum-=pow(2,i);
                for(int j = i-1 ;j>=0; j--){
                    if(input[j] > v[j]){
                        sum -= pow(2,j);
                    }
                        
                }
                // cout<<i<<" "<<notInd<<endl;
                notInd = -1;
            }
            // cout<<notInd<<endl;
        }
        if(notInd!=-1)
            return -1;
        return ans;
    }
};
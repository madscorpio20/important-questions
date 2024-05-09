class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long cnt = 0;
        sort(happiness.begin(),happiness.end());
        int n = happiness.size();
        long long j = 0;
        for(int i=n-1; i>=0; i--){
            long long curr = happiness[i];
            if(curr > j)
            cnt += (curr - j);
            else break;
            if(j+1 <k)j++;
            else break;
        }
        return cnt;
    }
};
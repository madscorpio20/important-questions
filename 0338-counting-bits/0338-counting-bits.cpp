class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i=1; i<=n; i++){
            int cnt = 0;
            int num = i;
            while(num> 0){
                if(num%2 == 1){
                    cnt++;
                }
                num =num/2;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
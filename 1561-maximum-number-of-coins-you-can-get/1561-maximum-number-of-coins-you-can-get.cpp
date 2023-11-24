class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i=0;
        int n = piles.size();
        int j = n-1;
        int ans = 0;
        while(i < j){
            j--;
            i++;
            ans+= piles[j];
            j--;
        }
        return ans;
    }
};
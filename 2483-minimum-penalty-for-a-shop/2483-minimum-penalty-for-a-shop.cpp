class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y')
                totalY++;

        }
        int cntY = 0;
        int cntN = 0;
        int minPanelty = INT_MAX;
        int ind = 0;
        for(int i=0; i<=n; i++){
            int currPanelty =  cntN + totalY-cntY;
            if(i < n && customers[i] == 'Y')
                cntY++;
            if(i < n && customers[i] == 'N')
                cntN++;
            if(currPanelty < minPanelty){
                minPanelty = currPanelty;
                ind = i;
            }
        }
        return ind;
    }
};
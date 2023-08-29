class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cntY = 0;
        map<int,int> m;
        m[n] = 0;
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y')
                cntY++;
            m[i] = cntY;

        }
        int cntN = 0;
        int minPanelty = INT_MAX;
        int ind = 0;
        for(int i=0; i<=n; i++){
            int currPanelty =  cntN + m[i];
            
            if(i < n && customers[i] == 'N')
                cntN++;
            // cout<<currPanelty<<endl;
            if(currPanelty < minPanelty){
                minPanelty = currPanelty;
                ind = i;
            }
        }
        return ind;
    }
};
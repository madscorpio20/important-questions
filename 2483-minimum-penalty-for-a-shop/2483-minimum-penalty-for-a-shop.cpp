class Solution {
public:
    int bestClosingTime(string customers) {
        int cntY = 0;
        map<int,int> m;
        m[customers.size()] = 0;
        for(int i=customers.size()-1; i>=0; i--){
            if(customers[i] == 'Y')
                cntY++;
            m[i] = cntY;

        }
        int cntN = 0;
        int minPanelty = INT_MAX;
        int ind = 0;
        for(int i=0; i<=customers.size(); i++){
            int currPanelty =  cntN + m[i];
            
            if(i < customers.size() && customers[i] == 'N')
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
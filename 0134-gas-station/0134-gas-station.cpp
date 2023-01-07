class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currFuel = 0;
        int start = -1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum+= gas[i] - cost[i];
        }
        if(sum < 0)
            return -1;
        for(int i=0; i< n; i++)
        {
            currFuel += gas[i] - cost[i];
            if(currFuel < 0)
            {
                start = -1;
                currFuel = 0;
            }
            else if(start == -1)
            {
                start = i;
            }
            
        }
        return start;
    }
};
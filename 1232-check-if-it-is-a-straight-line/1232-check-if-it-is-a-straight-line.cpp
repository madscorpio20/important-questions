class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double angle = ((double)coordinates[1][1]-(double)coordinates[0][1])/
            ((double)coordinates[1][0]-(double)coordinates[0][0]);
        if(coordinates[1][0] == coordinates[0][0])
        {
            for(int i=2; i<coordinates.size(); i++)
            {
                if(coordinates[i][0]!=coordinates[0][0])
                    return false;
            }
            return true;
        }
        cout<<angle<<endl;
        for(int i=2; i<coordinates.size(); i++)
        {
            double curr = ((double)coordinates[i][1]-(double)coordinates[0][1])/
            ((double)coordinates[i][0]-(double)coordinates[0][0]);
            if(curr!=angle)
                return false;
        }
        return true;
    }
};
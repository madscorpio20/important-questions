class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> output;
        vector<int> temp;
        temp.push_back(1);
        output.push_back(temp);
        temp.clear();
        for(int index=1; index<numRows; index++)
        {
            temp.push_back(1);
            for(int j=0; j+1<output[index-1].size(); j++)
            {
                temp.push_back(output[index-1][j]+output[index-1][j+1]);
            }
            temp.push_back(1);
            output.push_back(temp);
            temp.clear();
        }
        return output;
    }
};
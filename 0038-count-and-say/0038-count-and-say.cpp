class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string prev = countAndSay(n-1);
        string curr;
        for(int i=0; i<prev.size(); i++)
        {
            int cnt = 1;
            while(i+1<prev.size() && prev[i] == prev[i+1])
            {
                cnt++;
                i++;
            }
            curr+= to_string(cnt) + prev[i];
        }
        return curr;
    }
};
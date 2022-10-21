class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++)
        {
            int ind = i;
            int j=0;
            while(ind<haystack.size() && haystack[ind] == needle[j])
            {
                if(j==needle.size()-1)
                    return i;
                ind++;
                j++;
            }
        }
        return -1;
    }
};
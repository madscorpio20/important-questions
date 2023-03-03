class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0; 
        while(i<haystack.size())
        {
            if(haystack[i] == needle[0])
            {
                int j=i;
                int k=0;
                while(j<haystack.size() && k<needle.size() && haystack[j] == needle[k])
                {
                    j++;
                    k++;
                }
                if(k == needle.size())
                    return i;
            }
            i++;
            
        }
        return -1;
    }
};
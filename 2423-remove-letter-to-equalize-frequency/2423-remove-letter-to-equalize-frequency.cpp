class Solution {
public:
    bool equalFrequency(string word) {
        map<char,int> m;
        for(int i=0; i<word.size(); i++)
        {
            m[word[i]]++;
        }
        char ch;
        for(int i=0; i<26; i++)
        {
            ch = i + 'a';
            if(m[ch])
            {
                m[ch]--;
                int cnt = 0;
                bool check = true;
                for(auto it: m)
                {
                    if(it.second!=0)
                    {
                        if(cnt == 0)
                            cnt = it.second;
                        else if(cnt != it.second)
                        {
                            check = false;
                        }
                    }
                }
                if(check)
                    return true;
                m[ch]++;
            }
        }
        return false;
    }
};
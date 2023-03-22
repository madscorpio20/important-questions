class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int cnt = 0;
        unordered_map<string,int> m;
        unordered_map<string,int> availableWords;
        for(auto it: wordList)
        {
            availableWords[it]++;
        }
        m[beginWord]++;
        q.push(beginWord);
        while(!q.empty())
        {
            cnt++;
            int n = q.size();
            for(int k=0; k<n; k++)
            {
                string curr = q.front();
                q.pop();
                if(curr == endWord) return cnt;
                for(int i=0; i<curr.size(); i++)
                {
                    for(int j=0; j<26; j++)
                    {
                        string newWord = curr;
                        newWord[i] = j + 'a';
                        if(m[newWord]) continue;
                        if(availableWords[newWord])
                        {
                            q.push(newWord);
                            m[newWord]++;
                        }
                    }
                }
            }
            
        }
        return 0;
        
    }
};
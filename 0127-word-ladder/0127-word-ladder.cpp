class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        for(auto it: wordList){
            mp[it]++;
        }
        if(!mp[endWord]) return 0;
        map<string,int> vis;
        vis[beginWord]++;
        int cnt = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            cnt++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                string curr = q.front();
                q.pop();
                for(int j=0; j<curr.size(); j++){
                    string nxt = curr;
                    for(int k=0; k<26; k++){
                        nxt[j] = k + 'a';
                        if( mp[nxt] && !vis[nxt]){
                            vis[nxt] = 1;
                            if(nxt == endWord) return cnt+1;
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};
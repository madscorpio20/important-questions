class Trie 
{
    public: 
    vector<Trie*> children;
    bool isEnd;
    Trie()
    {
        children.resize(26,0);
        isEnd = false;
    }  
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        
        Trie *node = root;
        int ind = 0;
        while(ind < word.size())
        {
            if(!node->children[word[ind]- 'a'])
            {
                node->children[word[ind] - 'a'] = new Trie();
            }
            node = node->children[word[ind] - 'a'];
            ind++;
        }
        node->isEnd = true;
    }
    
    bool helpSearch(Trie *curr,string word, int ind)
    {
        if(ind == word.size()) return curr->isEnd;
        if(word[ind] == '.')
        {
            for(int i=0; i<26; i++)
            {
                if(curr->children[i] && helpSearch(curr->children[i],word,ind+1))
                    return true;
                    
            }
            return false;

        }
        if(curr->children[word[ind] - 'a'])
            return helpSearch(curr->children[word[ind] - 'a'],word,ind+1);
        return false;
    }
    bool search(string word) {
        Trie* curr = root;
        return helpSearch(curr,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class TrieNode {
    public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode () 
    {
        isEnd = false;
        children.resize(26,NULL);
    }
};
class Trie {
    public:
    TrieNode * root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->children[word[i]- 'a'] == NULL)
            {
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->children[word[i]- 'a'] == NULL)
            {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(node->children[prefix[i]- 'a'] == NULL)
            {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
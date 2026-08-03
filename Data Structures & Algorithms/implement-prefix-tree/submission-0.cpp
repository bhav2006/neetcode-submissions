class TrieNode
{
public:
    TrieNode* child[26];
    bool EOW;

    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
        EOW = false;
    }
};

class PrefixTree {
public:

    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* curr = root;
        for(char ch: word)
        {
            int idx = ch - 'a';
            if(curr->child[idx] == NULL)
            {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->EOW = true;
    }
    
    bool search(string word) 
    {
        TrieNode* curr = root;
        for(char ch: word)
        {
            int idx = ch - 'a';
            if(curr->child[idx] == NULL)
            {
                return false;
            }
            curr = curr->child[idx];
        }
        
        return curr->EOW;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* curr = root;
        for(char ch: prefix)
        {
            int idx = ch - 'a';
            if(curr->child[idx] == NULL)
            {
                return false;
            }
            curr = curr->child[idx];
        }
        
        return true;
    }
};

class TrieNode
{
    public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode()
    {
        for(int i = 0;i < 26;i++)
        {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};
class PrefixTree { 
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            int idx = c - 'a';
            if(node->children[idx] == nullptr)
            {
                return false;
            }
            node = node->children[idx];
        }
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(char c : prefix)
        {
            int idx = c - 'a';
            if(node->children[idx] == nullptr)
            {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

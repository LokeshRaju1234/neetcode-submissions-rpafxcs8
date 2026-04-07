class TrieNode
{
    public:
    unordered_map<char,TrieNode*> children;
    bool isword;

    TrieNode() : isword(false) {}

    void addword(string word)
    {
        TrieNode* curr = this;
        for(char c : word)
        {
            if(!curr->children.count(c))
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        curr->isword = true;
    }
};

class Solution {
    unordered_set<string>res;
    vector<vector<bool>> visit;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word : words)
        {
          root->addword(word);  
        }

        int r = board.size(),c = board[0].size();
        visit.assign(r,vector<bool>(c,false));
        for(int i = 0;i < r;i++)
        {
            for(int j = 0;j < c;j++)
            {
                dfs(i,j,board,root,"");
            }
        }
        return vector<string>(res.begin(),res.end());
    }

    private:
    void dfs(int i,int j,vector<vector<char>>& board,TrieNode* node,string word)
    {
        int r = board.size(),c = board[0].size();

        if(i < 0 || j < 0 || i >= r || j >= c || visit[i][j] || !node->children[board[i][j]])
        {
            return;
        }

        visit[i][j] = true;
        word += board[i][j];
        node = node->children[board[i][j]];
        if(node->isword)
        {
            res.insert(word);
        }

        dfs(i + 1,j,board,node,word);
        dfs(i,j - 1,board,node,word);
        dfs(i,j + 1,board,node,word);
        dfs(i - 1,j,board,node,word);
        visit[i][j] = false;
    }
};

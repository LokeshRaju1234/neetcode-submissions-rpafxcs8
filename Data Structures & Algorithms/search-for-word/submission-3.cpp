class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0;i < rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(dfs(i,j,0,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i,int j,int wordIdx,vector<vector<char>>& board,string word)
    {
        if(wordIdx == word.size())
        {
            return true;
        }

        // boundry check
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[wordIdx])
        {
            return false;
        }

        char  temp = board[i][j];
        board[i][j] = '#';
        bool res = dfs(i+1,j,wordIdx+ 1,board,word) ||
        dfs(i- 1,j,wordIdx+ 1,board,word) ||
        dfs(i,j+ 1,wordIdx+ 1,board,word) ||
        dfs(i,- 1,wordIdx+ 1,board,word);

        board[i][j] = temp;
        return res;
    }
};

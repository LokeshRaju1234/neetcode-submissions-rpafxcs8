class Solution {
   vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(),cols = heights[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));
        vector<vector<int>>res;

        for(int c = 0;c < cols;c++)
        {
            dfs(0,c,pac,heights);
            dfs(rows - 1,c,atl,heights);
        }

        for(int r = 0; r < rows;r++)
        {
            dfs(r,0,pac,heights);
            dfs(0,cols - 1,atl,heights);
        }

        for(int i = 0;i < rows;i++)
        {
            for(int j = 0; j < cols;j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    res.push_back(heights[i][j]);
                }
            }
        }

        return res;
    }

    void dfs(int r,int c,vector<vector<bool>>& ocean,vector<vector<int>>& heights)
    {
        ocean[r][c] = true;
        for(auto [dr,dc] : directions)
        {
            int nr = r + dr,nc = c + dc;
            if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
            {
                dfs(nr,nc,ocean,heights);
            }
        }   
    }
};

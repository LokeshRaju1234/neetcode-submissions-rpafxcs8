class Solution {
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(),c = grid[0].size();
        int island = 0;
        for(int i = 0;i < r;i++)
        {
            for(int j = 0;j < c;j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }

    void bfs(vector<vector<char>>& grid,int r,int c)
    {
        queue<pair<int,int>>q;
        grid[r][c] = '0';
        q.push({r,c});

        while(!q.empty())
        {
            auto node = q.front();q.pop();
            int row  = node.first,col = node.second;
            for(int i = 0;i < 4;i++)
            {
                int rd = row + dir[i][0],cd = col + dir[i][1];
                if(rd >= 0 && cd >= 0 && rd < grid.size() && cd < grid[0].size() && grid[rd][cd] == '1')
                {
                    q.push({rd,cd});
                    grid[rd][cd] = '0';
                }
            }
        }
    }
};

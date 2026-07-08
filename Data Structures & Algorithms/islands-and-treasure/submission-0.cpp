class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == INT_MAX)
                {
                    grid[r][c] = grid[row][col] + 1;
                    q.push({r,c});
                }
            }
        }
    }
};

class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    void DFS(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[i][j] = 1;

        for(int dir = 0; dir < 4; dir++)
        {
            int newR = i + dx[dir];
            int newC = j + dy[dir];

            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC] == '1')
            {
                DFS(newR,newC,n,m,vis,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int components = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '0')
                    continue;

                if(!vis[i][j])
                {
                    components++;
                    DFS(i,j,n,m,vis,grid);
                }
            }
        }

        return components;
    }
};

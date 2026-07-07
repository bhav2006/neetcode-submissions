class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int DFS(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        vis[i][j] = 1;
        int area = 1;

        for(int dir = 0; dir < 4; dir++)
        {
            int newR = i + dx[dir];
            int newC = j + dy[dir];

            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC] == 1)
            {
                area += DFS(newR,newC,n,m,vis,grid);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxArea = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                    continue;

                if(!vis[i][j])
                {
                    maxArea = max(maxArea,DFS(i,j,n,m,vis,grid));
                }
            }
        }

        return maxArea;
    }
};

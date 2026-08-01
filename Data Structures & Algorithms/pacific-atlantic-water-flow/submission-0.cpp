class Solution {
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        vis[i][j] = 1;

        for(int k=0;k<4;k++)
        {
            int r = i + dx[k];
            int c = j + dy[k];

            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c] >= grid[i][j])
            {
                DFS(r,c,grid,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            DFS(i,0,heights,pacific);
        }

        for(int j=0;j<m;j++)
        {
            DFS(0,j,heights,pacific);
        }

        for(int i=0;i<n;i++)
        {
            DFS(i,m-1,heights,atlantic);
        }

        for(int j=0;j<m;j++)
        {
            DFS(n-1,j,heights,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};

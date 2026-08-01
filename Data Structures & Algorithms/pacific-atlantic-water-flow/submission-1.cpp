class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             bool &pacific,
             bool &atlantic)
    {
        vis[i][j] = 1;

        // Reached Pacific
        if(i == 0 || j == 0)
            pacific = true;

        // Reached Atlantic
        if(i == n - 1 || j == m - 1)
            atlantic = true;

        // Optional pruning
        if(pacific && atlantic)
            return;

        for(int k = 0; k < 4; k++)
        {
            int r = i + dx[k];
            int c = j + dy[k];

            if(r >= 0 && c >= 0 && r < n && c < m &&
               !vis[r][c] &&
               heights[r][c] <= heights[i][j])
            {
                dfs(r, c, heights, vis, pacific, atlantic);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                vector<vector<int>> vis(n, vector<int>(m, 0));

                bool pacific = false;
                bool atlantic = false;

                dfs(i, j, heights, vis, pacific, atlantic);

                if(pacific && atlantic)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};
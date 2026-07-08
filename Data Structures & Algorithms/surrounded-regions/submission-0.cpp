class Solution {
public:

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    void DFS(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[i][j] = 1;

        for(int k=0;k<4;k++)
        {
            int r = i + dx[k];
            int c = j + dy[k];

            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[i][j] == 'O')
            {
                DFS(r,c,n,m,vis,grid);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O')
            {
                DFS(i,0,n,m,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(board[i][m-1] == 'O')
            {
                DFS(i,m-1,n,m,vis,board);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O')
            {
                DFS(0,j,n,m,vis,board);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(board[n-1][j] == 'O')
            {
                DFS(n-1,j,n,m,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

class Solution {
public:

    int n,m,sz;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool DFS(int i,int j,int idx,vector<vector<char>>& board, string& word)
    {
        if(idx == sz)
            return true;

        if(i<0 || j<0 || i>=n || j>=m)
            return false;

        if(board[i][j] != word[idx])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(DFS(ni, nj, idx + 1, board, word))
                return true;
        }

        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        n = board.size();
        m = board[0].size();
        sz = word.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(DFS(i,j,0,board,word))
                    return true;
            }
        }

        return false;
    }
};

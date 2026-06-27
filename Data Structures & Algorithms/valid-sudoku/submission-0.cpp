class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        map<pair<int,int>,int> row,col,box;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')    continue;

                int ele = board[i][j];

                if(row[{i,ele}] || col[{j,ele}] || box[{(i/3)*3+j/3,ele}])
                    return false;

                row[{i,ele}]=1;
                col[{j,ele}]=1;
                box[{(i/3)*3+j/3,ele}]=1;
            }
        }

        return true;
    }
};

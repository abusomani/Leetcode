class Solution {
private:
    vector<vector<int>> board;
    int res = 0, N;
    bool isPossible(int r, int c){
        for(int i=0; i<=r; i++)if(board[i][c])return false;
        for(int i=0; i<N; i++)if(board[r][i])return false;
        for(int i=r, j=c; i>=0 and j>=0; i--, j--)if(board[i][j])return false;
        for(int i=r, j=c; i>=0 and j<N; i--, j++)if(board[i][j])return false;
        return true;
    }
    void dfs(int row){
        if(row == N)
            res++;
        else{
            for(int i=0; i<N; i++)
            {
                if(isPossible(row, i))
                {
                    board[row][i] = 1;
                    dfs(row+1);
                    board[row][i] = 0;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        N = n;
        board.resize(N, vector<int>(N, 0));
        dfs(0);
        return res;
    }
};
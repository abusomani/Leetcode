class TicTacToe {
private:
    vector<int> R,C;
    int N, diag, anti;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        diag = 0; 
        anti = 0;
        R.resize(N, 0);
        C.resize(N, 0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        R[row]+= val;
        C[col]+= val;
        diag += row == col ? val : 0;
        anti += row + col == N-1 ? val : 0;
        return (abs(R[row]) == N or abs(C[col]) == N or abs(diag) == N or abs(anti) == N) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
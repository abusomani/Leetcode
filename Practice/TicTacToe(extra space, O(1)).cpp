class TicTacToe
{
private:
    //count parameter: player 1 + : player 2: -
    vector<int> rowJudge;
    vector<int> colJudge;
    int diag, anti;
    int N;

public:
    /** Initialize your data structure here. */

    TicTacToe(int n) : N(n), rowJudge(n), colJudge(n), diag(0), anti(0) {}

    int move(int row, int col, int player)
    {
        int add = player == 1 ? 1 : -1;       // increment or decrement based on player
        diag += row == col ? add : 0;         // row == col implies diagonal
        anti += row == N - col - 1 ? add : 0; // row == N - col - 1 implies anti diagonal
        rowJudge[row] += add;
        colJudge[col] += add;
        if (abs(rowJudge[row]) == N || abs(colJudge[col]) == N || abs(diag) == N || abs(anti) == N)
            return player;
        return 0;
    }
};
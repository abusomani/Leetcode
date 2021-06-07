#include <bits/stdc++.h>
using namespace std;
struct InvalidMoveException : public exception {
    const char * what() const throw(){
        return "Invalid move made! Please retry.";
    }
};
class Game{
public:
    vector<vector<int>> board;
    vector<int> height;
    int moves, N, M, gameOver;
    Game(int n, int m){
        N = n;
        M = m;
        board.resize(N, vector<int>(M, 0));
        moves = 0;
        gameOver = 0;
        height.resize(M, 0); // each column height < N
    }

    Game(Game &g){
        N = g.N;
        M = g.M;
        board = g.board;
        moves = g.moves;
        height = g.height;
        gameOver = g.gameOver;
    }

    ~Game(){}

    vector<int> calculate(int x, int y, int val){
        // Down, Left, Right, DD, DU, ADU, ADD 
        vector<int> res(7, 0);
        // DOWN
        for(int i=x; i<N; i++)
            res[0] += board[i][y] == val;
        // Left
        for(int i=y; i>=0; i--)
            res[1] += board[x][i] == val;
        //Right
        for(int i=y+1; i<M; i++)
            res[2] += board[x][i] == val;
        // DD
        for(int i=x, j=y; i<N and j >= 0; i++, j--)
            res[3] += board[i][j] == val;
        // DU
        for(int i=x-1, j=y+1; i >= 0 and j < M; i--, j++)
            res[4] += board[i][j] == val;
        // ADU
        for(int i=x, j=y; i >= 0 and j >= 0; i--, j--)
            res[5] += board[i][j] == val;
        // ADD
        for(int i=x+1, j=y+1; i <N and j < M; i++, j++)
            res[6] += board[i][j] == val;
        return res;
    }
    int getMovesPerformed(){
        return moves;
    }
    bool canPlay(int col){
        if(col < 0 or col >= M)
            throw InvalidMoveException();
        return height[col] < N;
    }
    bool isWinningMove(int col){
        int currentPlayer = 1 + moves%2;
        auto p = calculate(height[col], col, currentPlayer);
        return p[0] >= 3 or (p[1] + p[2] >= 3) or (p[3] + p[4] >= 3) or (p[5] + p[6] >= 3);
    }
    void play(int col){
        try{
            if(!gameOver and canPlay(col)){
                if(isWinningMove(col))
                {
                    gameOver = 1;
                    cout << (1 + moves%2) << " wins the game!\n";
                }
                board[height[col]][col] = 1 + moves%2; // Player 1 -> 1, player 2 -> 2
                height[col]++;
                moves++;
            }
        } catch(exception &e){
            cerr << e.what() << endl;
        }
    }

    void displayBoard(){
        cout << "Displaying the current board\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    int getScore(){
        return 0;
    }
};

// column , score
pair<int,int> maximizePlay(Game &g, int depth = 4){
    int score = g.getScore();
    if(g.getMovesPerformed() == g.N * g.M or depth == 0)
        return {-1, score};
    
    pair<int,int> bestScore = {-1, -99999};
    for(int x = 0; x < g.M; x++){
        if(g.canPlay(x)){
            Game g2(g);
            g2.play(x);
            auto P = maximizePlay(g2, depth-1);
            if(bestScore.first == -1 or P.second > bestScore.second){
                bestScore.first = x;
                bestScore.second = P.second;
            }
        }
    }
    return bestScore;
}

pair<int,int> minimizePlay(Game &g, int depth = 4){
    int score = g.getScore();
    if(g.getMovesPerformed() == g.N * g.M or depth == 0)
        return {-1, score};
    
    pair<int,int> bestScore = {-1, -99999};
    for(int x = 0; x < g.M; x++){
        if(g.canPlay(x)){
            Game g2(g);
            g2.play(x);
            auto P = maximizePlay(g2, depth-1);
            if(bestScore.first == -1 or P.second < bestScore.second){
                bestScore.first = x;
                bestScore.second = P.second;
            }
        }
    }
    return bestScore;
}

int main(){
    int x;
    Game g(7, 6);
    while(true){
        cin>>x;
        g.play(x);
        pair<int,int> P = maximizePlay(g);
        cout << "Score : " <<  P.second << " and col " << P.first << endl;
        g.displayBoard();
    }
    return 0;
};
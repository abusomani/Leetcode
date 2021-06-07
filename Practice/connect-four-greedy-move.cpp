#include <bits/stdc++.h>
using namespace std;
const int WIDTH = 7, HEIGHT = 6;
const int RED = 2, YELLOW = 1;
struct InvalidMoveException : public exception {
  const char * what() const throw(){
      return "Invalid move played";
  }  
};
class Player{
public:
    string name;
    Player(string n){
        name = n;
    }
};
class Game {
public: 
    Player * p1, *p2, *won;
    int N, M, moves, gameOver;
    vector<vector<int>> board;
    Game(){
        N = HEIGHT;
        M = WIDTH;
        board.resize(HEIGHT, vector<int>(WIDTH, 0));
        moves = 0;
        gameOver = 0;
        p1 = new Player("Player 1");
        p2 = new Player("Player 2");
        won = nullptr;
    }
    Game(Player *a, Player *b){
        p1 = a;
        p2 = b;
        N = HEIGHT;
        M = WIDTH;
        board.resize(HEIGHT, vector<int>(WIDTH, 0));
        moves = 0;
        gameOver = 0;
        won = nullptr;
    }
    
    Game(Game &g){
        N = g.N;
        M = g.M;
        board = g.board;
        moves = g.moves;
        gameOver = g.gameOver;
        p1 = g.p1;
        p2 = g.p2;
        won = g.won;
    }
    
    // ~Game(){
    //     delete p1;
    //     delete p2;
    // }
    
    int getCurrentPlayer(){
        // First player is Yellow and second player is Red
        return moves & 1 ? RED : YELLOW;
    }
    
    bool canMakeMove(int col){
        if(gameOver or moves == N * M or col < 0 or col >= M or findRow(col) == -1)
            throw InvalidMoveException();
        return true;
    }
    
    int findRow(int col){
        int i = 0;
        while(i < N and board[i][col] == 0)i++;
        return i-1;
    }
    
    bool isWinningMove(int row, int col, int val){
        vector<int> res(7, 0);
        // Down, left, right, dd, du, adu, add
        for(int i=row; i  < N and board[i][col] == val; i++, res[0]++){}
        for(int i=col; i >= 0 and board[row][i] == val; i--, res[1]++){}
        for(int i=col+1; i < M and board[row][i] == val; i++, res[2]++){}
        for(int i=row, j=col; i < N and j >=0 and board[i][j] == val; i++, j--, res[3]++){}
        for(int i=row-1, j=col+1; i >= 0 and j < M and board[i][j] == val; i--, j++, res[4]++){}
        for(int i=row, j=col; i >= 0 and j >=0 and board[i][j] == val; i--, j--, res[5]++){}
        for(int i=row+1, j=col+1; i < N and j < M and board[i][j] == val; i++, j++, res[6]++){}
        return res[0] >= 4 or (res[1] + res[2] >= 4) or (res[3] + res[4] >= 4) or (res[5] + res[6] >= 4);
    }
    
    int smartMove(Game g, Player *p){
        Game g2(g);
        for(int col=0; col<M; col++){
            try{
                if(g2.canMakeMove(col))
                    g2.makeMove(col);
                if(g.won and g.won->name == p->name){
                    return col;
                }
            } catch(exception &e){
            }
        }
        return rand()%g.M;    
    }
    
    void makeMove(int col){
        try {
            if(canMakeMove(col)){
                int currentPlayer = getCurrentPlayer();
                int row = findRow(col);
                board[row][col] = currentPlayer;
                moves++;
                if(isWinningMove(row, col, currentPlayer)){
                    cout << currentPlayer << " has won!" << endl;
                    gameOver = 1;
                    won = currentPlayer == RED ? p2 : p1;
                }
            }
        } catch (exception &e) {
            cout << e.what() << " for column " << col << ".Please retry!"  << endl;
        }
    }
    
    void displayBoard(){
        cout << "Printing the current state of the board\n";
        for(int i=0; i < N; i++){
            for(int j=0; j<M; j++){
                cout << board[i][j] << " ";
            }
            cout <<endl;
        }
    }
};

int main() {
    srand(time(nullptr));
    Player *A = new Player("Abhishek Somani"); // YELLOW
    Player *B = new Player("Mihai Anca"); // RED
    Game g(A, B);
    while(true){
        if(g.getCurrentPlayer() == RED) {
            int col = g.smartMove(g, B);
            while(!g.canMakeMove(col)){
                col = rand() % g.M;
            }
            g.makeMove(col);
        } else {
            int col = rand() % g.M;
            while(!g.canMakeMove(col)){
                col = rand() % g.M;
            }
            g.makeMove(col);
        }
        g.displayBoard();
        if(g.gameOver){
            cout << "Game Over!" << endl;
            break;
        }
        if(g.moves == g.N * g.M) {
            cout << "It's a draw!"<<endl;
            break;
        }
    }
    return 0;
}

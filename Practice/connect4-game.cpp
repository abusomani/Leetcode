#include <bits/stdc++.h>
#include <exception>
using namespace std;
const int RED = 1, BLUE = 2;
struct InvalidPositionException : public exception {
    const char * what() const throw() {
        return "Invalid position for placing the dot";
    }
};
class Player {
private:
    string name;
public:
    string getName(){return name;}
    void setName(string n){name = n;}
    Player(string n){
        name = n;
    }
    ~Player(){}
};
class Board {
private:
    int N, M;
    vector<vector<int>> B;
public:
    Board(int n, int m){
        N = n;
        M = m;
        B.resize(N, vector<int>(M, 0));
    }
    ~Board(){}
    int getN(){return N;}
    int getM(){return M;}
    vector<vector<int>> getBoard(){return B;}
    // returns the last row where the value was entered
    int addDot(int y, int val){
        // if out of bounds or if the column is full
        if(y < 0 or y >= M or B[0][y] != 0)
            throw InvalidPositionException();
        int x = getN()-1;
        while(x > 0 and B[x][y])x--;
        B[x][y] = val;
        return x;
    }
};
class Connect4 {
private:
    int N, M;
    Board *board;
    Player *p1, *p2;
    bool playerOneTurn, gameOver;

    vector<int> calculate(int x, int y, int val){
        // Down, Left, Right, DD, DU, ADU, ADD 
        auto b = board->getBoard();
        vector<int> res(7, 0);
        // DOWN
        for(int i=x; i<N; i++)
            res[0] += b[i][y] == val;
        // Left
        for(int i=y; i>=0; i--)
            res[1] += b[x][i] == val;
        //Right
        for(int i=y+1; i<M; i++)
            res[2] += b[x][i] == val;
        // DD
        for(int i=x, j=y; i<N and j >= 0; i++, j--)
            res[3] += b[i][j] == val;
        // DU
        for(int i=x-1, j=y+1; i >= 0 and j < M; i--, j++)
            res[4] += b[i][j] == val;
        // ADU
        for(int i=x, j=y; i >= 0 and j >= 0; i--, j--)
            res[5] += b[i][j] == val;
        // ADD
        for(int i=x+1, j=y+1; i <N and j < M; i++, j++)
            res[6] += b[i][j] == val;
        return res;
    }

public:
    Connect4(int n, int m, string n1, string n2){
        N = n;
        M = m;
        board = new Board(n, m);
        p1 = new Player(n1);
        p2 = new Player(n2);
        playerOneTurn = true;
        gameOver = false;
    }

    ~Connect4(){
        delete board;
        delete p1;
        delete p2;
    }

    void toggle(){
        playerOneTurn = !playerOneTurn;
    }

    void displayBoard(){
        cout << "Current board state\n";
        auto b = board->getBoard();
        for(int i=0; i<N; i++)
            {
                for(int j=0; j<M; j++)
                    cout<< b[i][j] << " ";
                cout << endl;
            }
    }

    void makeMove(int y){
        if(gameOver) {
            cout << "Game is over! Start a new game!";
            return;
        }
        int val = playerOneTurn ? RED : BLUE;
        try {
            int row = board->addDot(y, val);
            if(isWinner(row, y, val)){
                gameOver = true;
                cout << "Woohoo! " << (playerOneTurn? p1->getName() : p2->getName()) << " wins\n";
            }
            toggle(); 
        } catch(exception &e){
            cerr << e.what() << " column " <<  y << endl;
        }
    }

    bool isWinner(int x, int y, int val){
        auto p = calculate(x, y, val);
        return p[0] == 4 or (p[1] + p[2] == 4) or (p[3] + p[4] == 4) or (p[5] + p[6] == 4);
    }

};


int main(){
    Connect4 game(7, 6, "Abhishek", "Somani");
    int col;
    while(true){
        cin>> col;
        game.makeMove(col);
        game.displayBoard();
    }
    return 0;
}
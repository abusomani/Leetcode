class Solution {
private:
    vector<int> R, C;
    int diag = 0, anti = 0;
    int move(int x, int y, int player){
        R[x] += player;
        C[y] += player;
        diag += x == y ? player : 0;
        anti += x == 2-y ? player : 0;
        if(abs(R[x]) == 3 || abs(C[y]) == 3 || abs(diag) == 3 || abs(anti) == 3)
            return player;
        return 0;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        R.resize(3, 0);
        C.resize(3, 0);
        bool A = true;
        for(auto m: moves){
            int val = move(m[0], m[1], A ? 1 : -1);
            if(val != 0)
                return val == 1 ? "A" : "B";
            A = !A;
        }
        return moves.size() == 9 ? "Draw": "Pending";
    }
};
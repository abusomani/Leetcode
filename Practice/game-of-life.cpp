//The only trick is to denote live --> die as -1 and die --> live as 2
class Solution {
private:
    int dx[8] = {-1,1,0,0,1,1,-1,-1};
    int dy[8] = {0,0,-1,1,1,-1,-1,1};
    int value(int i, int j, int N, int M, vector<vector<int>> &B) {
        if(i < 0 or i >= N or j < 0 or j >= M)return 0;
        return B[i][j];
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int N = board.size(), M = board[0].size();
        vector<vector<int>> dup(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++) {
                int cnt = 0;
                for(int k=0; k<8; k++)
                    cnt += value(i+dx[k], j+dy[k], N, M, board);

                if(board[i][j]) {
                    if(cnt == 2 or cnt == 3)
                        dup[i][j] = 1;
                } else {
                    if(cnt == 3)
                        dup[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                board[i][j] = dup[i][j];
    } 
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if(N == 0 or M == 0)
            return {};
        
        int i = 0, j = 0, d = -1, cnt = 0;
        vector<int> res;
        while(res.size() < N*M) {
            res.push_back(matrix[i][j]);
            i += d;
            j += -d;
            if(i > N-1) {
                i = N-1;
                j += 2;
                d = -d;
            }
            if(j > M-1) {
                j = M-1;
                i += 2;
                d = -d;
            }
            if(i < 0) {
                i = 0;
                d = -d;
            }
            if(j < 0) {
                j = 0;
                d = -d;
            }
        }
        return res;
    }
};
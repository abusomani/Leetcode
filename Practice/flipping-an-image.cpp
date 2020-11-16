class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int N = A.size(), M = A[0].size();
        for(int i=0; i<N; i++) {
            reverse(A[i].begin(), A[i].end());
            for(int j=0; j<M; j++)
                A[i][j] = !A[i][j];
        }
        return A;
    }
};
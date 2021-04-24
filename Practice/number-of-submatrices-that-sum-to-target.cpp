class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, N = A.size(), M = A[0].size();
        for (int i = 0; i < N; i++)
            for (int j = 1; j < M; j++)
                A[i][j] += A[i][j - 1];

        unordered_map<int, int> counter;
        for (int c1 = 0; c1 < M; c1++) {
            for (int c2 = c1; c2 < M; c2++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < N; k++) {
                    cur += A[k][c2] - (c1 > 0 ? A[k][c1 - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};
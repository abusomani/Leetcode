class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, multiset<int>> Mp;
        int N = mat.size(), M = mat[0].size();
        for(int i=0;i <N; i++)
            for(int j=0; j<M; j++)
                Mp[j-i].insert(mat[i][j]);
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++) {
                auto it = Mp[j-i].begin();
                mat[i][j] = *it;
                Mp[j-i].erase(it);
            }
        
        return mat;
    }
};
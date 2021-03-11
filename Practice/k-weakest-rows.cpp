class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int N = mat.size(), M = mat[0].size();
        vector<pair<int,int>> res(N, {0,0});
        for(int i=0; i<N; i++) {
            res[i].first = i;
            for(int j=0; j<M; j++) {
                if(mat[i][j] == 0)break;
                res[i].second++;
            }
        }
        
        sort(res.begin(), res.end(), [&](const pair<int,int> &P, const pair<int,int> &Q) {
            return (P.second == Q.second) ? P.first < Q.first : P.second < Q.second;
        });
        vector<int> V;
        for(int i=0; i<k; i++)
            V.push_back(res[i].first);
        return V;
    }
};
class Solution {
private:
    bool dfs(vector<int> &M, vector<int> &buckets, int idx, int side){
        if(idx == M.size()){
            for(int i=0; i<4; i++)
                if(buckets[i] != side)
                    return false;
            return true;
        }
        if(M[idx] > side)return false;
        for(int i=0; i<4; i++){
            if(buckets[i] + M[idx] <= side){
                buckets[i] += M[idx];
                if(dfs(M, buckets, idx+1, side))
                    return true;
                buckets[i] -= M[idx];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& M) {
        if(M.size() < 4)return false;
        int total = accumulate(M.begin(), M.end(), 0);
        if(total % 4 != 0)return false;
        sort(M.rbegin(), M.rend());
        vector<int> buckets(4, 0);
        return dfs(M, buckets, 0, total/4);
    }
};
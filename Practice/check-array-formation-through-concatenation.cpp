class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int N = arr.size();
        unordered_map<int,int> Mp;
        for(int i=0; i<N; i++)Mp[arr[i]] = i;
        
        for(auto &piece : pieces) {
            int sz = piece.size(), val = piece[0], j = 0;
            if(sz > 1) {
                for(int i=Mp[val]; i<N and j<sz; i++, j++) {
                    if(arr[i] != piece[j])
                        return false;
                }
                if(j != sz)
                    return false;
            } else {
                if(!Mp.count(val))return false;
            }
        }
        return true;
    }
};
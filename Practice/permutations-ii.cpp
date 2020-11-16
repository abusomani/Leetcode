class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while(true) {
            if(next_permutation(nums.begin(), nums.end()))
                res.push_back(nums);
            else
                break;
        }
        return res;
    }

    bool nextPermutation(vector<int> &V) {
        int N = V.size(), k , l;
        for(k=N-2; k>=0; k--)
            if(V[k] < V[k+1])
                break;
        if(k < 0)return false;
        for(l=N-1; l>k;l--)
            if(V[l] > V[k])
                break;
        swap(V[l], V[k]);
        reverse(V.begin()+k+1, V.end());
        return true;
    }
};
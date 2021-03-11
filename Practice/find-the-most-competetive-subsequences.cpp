class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size(), toDelete = N-k;
        vector<int> res;
        for(int i=0; i<N; i++) {
            while(!res.empty() and res.back() > nums[i] and toDelete) {
                res.pop_back();
                toDelete--;
            }
            res.push_back(nums[i]);
        }
        return vector<int>(res.begin(), res.begin()+k);
    }
};
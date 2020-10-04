class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int N = nums.size(), ans = 0;
        unordered_map<int,int> Mp;
        for(auto &num : nums)Mp[num]++;
        for(auto &i : Mp) {
            int v = i.first + k;
            if(k == 0) {
                ans += Mp[v] > 1 ? 1 : 0;
            }
            else if(Mp.count(v))
                ans++;
        }
        return ans;
    }
};
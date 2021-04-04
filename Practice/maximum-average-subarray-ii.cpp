// Key optimization is to check from range [k, 2k-1]. Bigger range of 2k can be subdivided again.
// Brute force complexity is O(n*k)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN;
        vector<int> prefix;
        prefix.push_back(0);
        for(auto &num: nums)
            prefix.push_back(prefix.back()+num);
        for(int i=0; i<nums.size(); i++) {
            for(int len=k; len+i<prefix.size() and len <= 2*k -1; len++)
            {
                double s = prefix[i+len] - prefix[i];
                res = max(res, s/len);
            }
        }
        return res;
    }
};
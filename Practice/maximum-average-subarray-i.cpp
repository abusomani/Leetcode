class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN, sm = 0;
        for(int i=0; i<k; i++)
            sm += nums[i];
        for(int i=k; i<= nums.size(); i++)
        {
            res = max(res, sm);
            if(i == nums.size())break;
            sm -= nums[i-k];
            sm += nums[i];
        }
        return res / k;
    }
};
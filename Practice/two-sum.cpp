#include <bits/stdc++.h>
using namespace std;

/*
    Find two elements sum equals target in unsorted array.
    Use unordered map for Linear time complexity.
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> Mp;
        vector<int> V;
        for (int i = 0; i < nums.size(); i++)
        {
            if (Mp.find(target - nums[i]) != Mp.end())
            {
                V.push_back(min(i, Mp[target - nums[i]]));
                V.push_back(max(i, Mp[target - nums[i]]));
                return V;
            }
            Mp.insert(make_pair(nums[i], i));
        }
        return V;
    }
};
//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int N = arr.size();
        int left = 0, right = N - 1;
        vector<int> V;
        while (left < right)
        {
            int val = arr[left] + arr[right];
            if (val == target)
            {
                V.push_back(left + 1);
                V.push_back(right + 1);
                break;
            }
            else if (val < target)
                left++;
            else
                right--;
        }
        return V;
    }
};
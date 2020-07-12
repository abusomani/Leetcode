typedef long long ll;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        ll fromBegin = 1, fromEnd = 1, N = nums.size();
        vector<int> res(N, 1);

        for (int i = 0; i < N; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];

            res[N - i - 1] *= fromEnd;
            fromEnd *= nums[N - i - 1];
        }
        return res;
    }
};

/*
1 1 2 6
24 12 4 1
*/
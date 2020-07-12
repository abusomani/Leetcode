/*
Either maximum is somewhere between [a,b,c,(d,e,f,g,h),i,j,k]
Else  maximum is wrapping between [a,b),c,d,e,f,g,h,(i,j,k]
Wrapping can be represented by => [(a,b),c,d,e,f,g,h,(i,j,k)]
Which in turn is => Total array sum - [a,b,(c,d,e,f,g,h),i,j,k]
Answer = max(TotalSum - MinArraySum , MaxArraySum);
*/
#define ll long long
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int N = A.size();
        if (N == 0)
            return 0;
        int total = 0, maxSum = INT_MIN, currMax = 0, minSum = INT_MAX, currMin = 0;
        for (auto &a : A)
        {
            currMax = max(a, currMax + a);
            maxSum = max(maxSum, currMax);
            currMin = min(a, currMin + a);
            minSum = min(minSum, currMin);
            total += a;
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
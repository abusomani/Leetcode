class Solution
{
public:
    bool doable(vector<int> &nums, int M, long maxSum)
    {
        long sum = 0, cuts = M;
        for (auto &num : nums)
        {
            if (num > maxSum)
                return false;
            if (sum + num <= maxSum)
                sum += num;
            else
            {
                cuts--;
                sum = num;
                if (cuts < 0) // more than M cuts
                    return false;
            }
        }
        // less than M cuts implies, we can even break them, implies its true
        return cuts >= 0;
    }
    int splitArray(vector<int> &nums, int m)
    {
        long boundaryLeft = 0, boundaryRight = 0;
        for (auto &num : nums)
        {
            // because largest element has to be part of some subarray
            boundaryLeft = max(boundaryLeft, (long)num);
            boundaryRight += num;
        }

        while (boundaryLeft < boundaryRight)
        {
            long mid = boundaryLeft + (boundaryRight - boundaryLeft) / 2;
            if (doable(nums, m - 1, mid))
                boundaryRight = mid;
            else
                boundaryLeft = mid + 1;
        }

        return boundaryLeft;
    }
};
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }
    int hammingWeight1(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
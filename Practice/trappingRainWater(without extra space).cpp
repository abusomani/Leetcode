class Solution
{
public:
    int trap(vector<int> &height)
    {
        int N = height.size();
        if (N == 0)
            return N;

        int ans = 0, l = 0, r = N - 1, lmax = 0;
        for (int i = 0; i < N; i++)
        {
            lmax = max(lmax, height[l] < height[r] ? height[l++] : height[r--]);
            ans += lmax - height[i];
        }

        return ans;
    }
};
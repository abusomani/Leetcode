class Solution
{
public:
    int numOfDigits(int num)
    {
        int cnt = 0;
        while (num)
        {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            ans += numOfDigits(num) & 1 ? 0 : 1;
        }
        return ans;
    }
};
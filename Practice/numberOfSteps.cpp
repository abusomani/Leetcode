class Solution
{
public:
    int numberOfSteps(int num)
    {
        int cnt = 0;
        while (num != 0)
        {
            num = (num & 1) ? num - 1 : num >> 1;
            cnt++;
        }
        return cnt;
    }
};
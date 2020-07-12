//Time complexity => O(NlogN)
class Solution
{
public:
    int rotatedDigits(int N)
    {
        int res = 0;
        //                       0  1  2  3  4  5  6  7  8  9
        vector<int> must_have = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
        vector<int> cant_have = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0};
        for (int i = 1; i <= N; ++i)
        {
            int m = 0, c = 0, num = i;
            while (num)
            {
                int digit = num % 10;
                if (cant_have[digit])
                {
                    ++c;
                    break;
                }
                if (must_have[digit])
                    ++m;
                num /= 10;
            }
            if (c)
                continue; // if you have cant_have number
            if (!m)
                continue; // if you don't have must_have number
            res++;
        }
        return res;
    }
};
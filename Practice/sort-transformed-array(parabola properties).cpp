/*
Function is a parabola
1.a>0, two ends in original array are bigger than center if you learned middle school math before.

2.a<0, center is bigger than two ends.
*/
typedef long long ll;
class Solution
{
public:
    int quad(const int &a, const int &b, const int &c, int x)
    {
        return (a * x * x + b * x + c);
    }
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c)
    {
        int N = nums.size(), i = 0, j = N - 1, left, right;
        vector<int> result(N, 0);
        int idx = (a >= 0) ? N - 1 : 0;
        // if a < 0, center is biggest, if a > 0, ends are highest
        while (i <= j)
        {
            left = quad(a, b, c, nums[i]);
            right = quad(a, b, c, nums[j]);
            if (a >= 0)
            {
                if (left >= right)
                    i++;
                else
                    j--;
                result[idx--] = left >= right ? left : right;
            }
            else
            {
                if (left >= right)
                    j--;
                else
                    i++;
                result[idx++] = left >= right ? right : left;
            }
        }
        return result;
    }
};
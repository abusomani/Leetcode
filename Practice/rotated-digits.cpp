// Time complexity => O(NlogN)
class Solution
{
private:
    int valid[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

public:
    bool isValid(int num)
    {
        int newNum = 0, orig = num;
        string tmp = to_string(num);
        for (int i = 0; i < tmp.size(); i++)
        {
            if (valid[tmp[i] - '0'] == -1)
                return false;
            newNum = newNum * 10 + valid[tmp[i] - '0'];
        }
        return (newNum != orig);
    }
    int rotatedDigits(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; i++)
            ans += isValid(i) ? 1 : 0;
        return ans;
    }
};
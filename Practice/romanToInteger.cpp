class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0, N = s.size(), i = 0;
        if (N == 0)
            return 0;

        int Value[24] = {0};
        Value['I' - 'A'] = 1;
        Value['V' - 'A'] = 5;
        Value['X' - 'A'] = 10;
        Value['L' - 'A'] = 50;
        Value['C' - 'A'] = 100;
        Value['D' - 'A'] = 500;
        Value['M' - 'A'] = 1000;

        while (i < N)
        {
            if (i + 1 < N and Value[s[i] - 'A'] < Value[s[i + 1] - 'A'])
                ans += -(Value[s[i] - 'A']);
            else
                ans += Value[s[i] - 'A'];
            i++;
        }

        return ans;
    }
};
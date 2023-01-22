class Solution
{
public:
    int maximumSwap(int num)
    {
        string number = to_string(num);
        int N = number.size();
        // start from back, whenever you get maximum digit, update, maximum idx and digit
        // while coming left any number less than max_digit is our candidate. So set l and r for it.
        int max_digit = -1, max_idx = -1, l = -1, r = -1;
        for (int i = N - 1; i >= 0; i--)
        {
            if (number[i] > max_digit)
            {
                max_digit = number[i];
                max_idx = i;
                continue;
            }
            if (number[i] < max_digit)
            {
                l = i;
                r = max_idx;
            }
        }
        if (l == -1)
            return num;
        swap(number[l], number[r]);
        return stoi(number);
    }
};
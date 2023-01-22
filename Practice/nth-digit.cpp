class Solution
{
public:
    int findNthDigit(int n)
    {
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        long start = pow(10, digits - 1);
        long offset = (n - 1) / digits, index = (n - 1) % digits;
        return to_string(start + offset)[index] - '0';
    }
};
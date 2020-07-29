class Solution1
{
public:
    int sum(int n)
    {
        int s = 0;
        while (n)
            s += n % 10, n /= 10;
        return s;
    }
    int addDigits(int num)
    {
        if (num < 10)
            return num;
        else
        {
            int s = sum(num);
            return addDigits(s);
        }
    }
};
//https://en.wikipedia.org/wiki/Digital_root
class Solution
{
public:
    int addDigits(int num)
    {
        return (num == 0) ? 0 : (num % 9) ? num % 9 : 9;
    }
};
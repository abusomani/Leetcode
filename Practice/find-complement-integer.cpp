class Solution
{
public:
    int findComplement(int N)
    {
        if (N == 0)
            return 1;
        int toDo = N, bit = 1;
        while (toDo)
        {
            N = N ^ bit;
            bit <<= 1;
            toDo >>= 1;
        }
        return N;
    }
};
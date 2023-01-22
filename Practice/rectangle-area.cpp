class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long abcd = (A - C) * (B - D);
        long efgh = (E - G) * (F - H);
        long common = overlapping(A, C, E, G) * overlapping(B, D, F, H);

        return (int)(abcd + efgh - common);
    }
    long overlapping(int A, int C, int E, int G)
    {
        if (C < E or A > G)
            return 0;
        return min(C, G) - max(A, E);
    }
};
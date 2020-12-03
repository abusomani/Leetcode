class Solution
{
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int mirrorReflection(int p, int q)
    {
        int g = gcd(p, q);
        p /= g;
        p %= 2;
        q /= g;
        q %= 2;
        return (p == 0 and q == 1) ? 2 : (p == 1 and q == 1) ? 1 : 0;
    }
};
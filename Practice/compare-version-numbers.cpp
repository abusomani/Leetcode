class Solution
{
private:
    // replace dots with spaces for istringstream
    void transform(string &a)
    {
        for (auto &s : a)
            if (s == '.')
                s = ' ';
    }

public:
    int compareVersion(string version1, string version2)
    {
        transform(version1);
        transform(version2);
        istringstream s1(version1), s2(version2);
        while (1)
        {
            int n1, n2;
            if (!(s1 >> n1))
                n1 = 0;
            if (!(s2 >> n2))
                n2 = 0;
            if (!s1 and !s2)
                return 0;
            if (n1 < n2)
                return -1;
            else if (n1 > n2)
                return 1;
        }
    }
    int compareVersionPureLogic(string v1, string v2)
    {
        int N = v1.size(), M = v2.size();
        int i = 0, j = 0;
        long n1 = 0, n2 = 0;
        while (i < N or j < M)
        {
            while (i < N and v1[i] != '.')
                n1 = n1 * 10 + (v1[i++] - '0');

            while (j < M and v2[j] != '.')
                n2 = n2 * 10 + (v2[j++] - '0');

            if (n1 < n2)
                return -1;
            else if (n1 > n2)
                return 1;

            n1 = 0;
            n2 = 0;
            i++; // for dot or end
            j++; // for dot or end
        }
        return 0;
    }
};
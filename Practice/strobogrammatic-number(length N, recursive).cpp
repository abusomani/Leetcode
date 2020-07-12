class Solution
{
private:
    vector<string> result; // not set because, the way we traverse it would always be unique
    int strob[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

public:
    char toChar(int a) { return (a + '0'); }

    void dfs(int n, string s, int l, int r)
    {
        if (l > r) // entire string is ready
        {
            result.push_back(s);
            return;
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (l == 0 and i == 0) // no leading zeroes
                    continue;

                if (strob[i] != -1 and l < r) // when l < r, we can use any valid mapping
                {
                    s[l] = toChar(i);
                    s[r] = toChar(strob[i]);
                    dfs(n, s, l + 1, r - 1);
                }

                else if (strob[i] == i and l == r) // when l == r , we can only use mapping of (i to strob[i])
                {
                    s[l] = toChar(i);
                    s[r] = toChar(strob[i]);
                    dfs(n, s, l + 1, r - 1);
                }
            }
        }
    }
    vector<string> findStrobogrammatic(int n)
    {
        if (n == 0)
            return vector<string>();
        string str(n, '#');
        dfs(n, str, 0, n - 1);
        if (n == 1)
            result.push_back("0");
        return result;
    }
};
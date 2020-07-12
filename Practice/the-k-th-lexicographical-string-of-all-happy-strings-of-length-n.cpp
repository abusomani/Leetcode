class Solution
{
    vector<string> result; // Maps all lexicographically sorted strings with its string size
public:
    vector<char> C = {'a', 'b', 'c'};
    void BFS(int n)
    {
        int level = 0; // levels also represent the size of string that is processed
        queue<string> Q;
        for (char ch = 'a'; ch <= 'c'; ch++)
            Q.push(string(1, ch));

        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                string s = Q.front();
                Q.pop();
                if (s.size() == n)
                    result.push_back(s);
                for (int i = 0; i < 3; i++)
                    if (s.back() != C[i]) // should not be same as previous character to make it happy
                        Q.push(s + C[i]);
            }
            level++;
            if (level > n) // if done with all strings of size n
                return;
        }
    }
    string getHappyString(int n, int k)
    {
        BFS(n);
        return k > result.size() ? "" : result[k - 1];
    }
};
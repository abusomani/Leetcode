class Solution
{
public:
    string countAndSay(int n)
    {
        string start = "1";
        while (--n)
        {
            int cnt = 1;
            string newS = "";
            for (int i = 1; i < start.size(); i++)
            {
                if (start[i] != start[i - 1])
                {
                    newS += to_string(cnt) + start[i - 1];
                    cnt = 1;
                }
                else
                    cnt++;
            }

            newS += to_string(cnt) + start[start.size() - 1];
            start = newS;
        }

        return start;
    }
};
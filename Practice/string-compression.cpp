class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int read = 1, cnt = 1, write = 0, N = chars.size();
        if (N <= 1)
            return N;
        char lastRead = chars[0];
        while (read < N)
        {
            if (chars[read] == chars[read - 1])
                cnt++;
            else
            {
                chars[write++] = lastRead;
                if (cnt != 1)
                {
                    string count = to_string(cnt);
                    for (int i = 0; i < count.size(); i++)
                        chars[write++] = count[i];
                }
                cnt = 1;                // reset count
                lastRead = chars[read]; // update last char
            }

            read++;
        }
        chars[write++] = lastRead;
        if (cnt != 1)
        {
            string count = to_string(cnt);
            for (int i = 0; i < count.size(); i++)
                chars[write++] = count[i];
        }

        return write;
    }

    int compressSimple(vector<char> &chars)
    {
        int write = 0;
        for (int read = 1, count = 1; read <= chars.size(); read++, count++)
        {
            if (read == chars.size() or chars[read] != chars[read - 1]) // Nth position also you would write
            {
                chars[write++] = chars[read - 1];
                if (count >= 2)
                {
                    for (auto &ch : to_string(count))
                        chars[write++] = ch;
                }
                count = 0;
            }
        }

        return write;
    }
};
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
private:
    char buffer[4];
    int len = 0, buffCnt = 0;

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int i = 0;
        while (i < n)
        {
            if (buffCnt >= len)
            {
                len = read4(buffer);
                buffCnt = 0;
                if (len == 0)
                    break;
            }
            buf[i++] = buffer[buffCnt++];
        }

        return i;
    }
};
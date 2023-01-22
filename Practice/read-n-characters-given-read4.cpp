/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution
{
private:
    char buffer[4];
    int len, buffCnt = 0;

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
                if (len == 0)
                    break;
                buffCnt = 0;
            }
            buf[i++] = buffer[buffCnt++];
        }
        return i;
    }
};
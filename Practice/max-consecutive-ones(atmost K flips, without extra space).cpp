class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int begin = 0, end = 0, N = A.size(), counter = 0, ans = 0;
        while (end < N)
        {
            if (A[end++] == 0)
            {
                counter++;
                while (counter > K)
                {
                    while (A[begin] != 0)
                        begin++;
                    begin++;
                    counter--;
                }
            }
            ans = max(ans, end - begin);
        }

        return ans;
    }

    int longestOnes1(vector<int> &A, int K)
    {
        int N = A.size(), begin = 0, end = 0, counter = 0, ans = 0;
        vector<int> cnt(2, 0);
        while (end < N)
        {
            cnt[A[end++]]++;
            if (A[end - 1] == 0 and cnt[0] > K)
                counter = 1;
            while (counter)
            {
                cnt[A[begin++]]--;
                if (A[begin - 1] == 0 and cnt[0] <= K)
                    counter--;
            }
            ans = max(ans, end - begin);
        }

        return ans;
    }
};
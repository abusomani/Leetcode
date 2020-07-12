class Solution
{
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, int> Bmp;
        int N = B.size(), M = A.size();
        for (int i = 0; i < N; i++)
            Bmp[B[i]] = i;

        vector<int> result;
        for (int i = 0; i < M; i++)
            result.push_back(Bmp[A[i]]);

        return result;
    }
};
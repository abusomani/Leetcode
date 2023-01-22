class Solution
{
public:
    /*
        Simulate the reversal with the logic that we need to place the largest element to the end.
        So in each iteration find the index of largest element in Kth iteration
        If we reverse till this idx, and then reverse K where K implies this element is Kth largest in array
    */
    vector<int> pancakeSort(vector<int> &A)
    {
        int N = A.size();
        vector<pair<int, int>> V;
        for (int i = 0; i < N; i++)
            V.push_back({A[i], i + 1});
        sort(V.begin(), V.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        vector<int> result;
        while (N > 0)
        {
            int idx = -1;
            for (int i = 0; i < A.size(); i++)
                if (A[i] == N)
                {
                    idx = i;
                    break;
                }

            result.push_back(idx + 1);
            reverse(A.begin(), A.begin() + idx + 1);
            reverse(A.begin(), A.begin() + N);
            result.push_back(N--);
        }
        return result;
    }
};
/*
4231
1324

*/
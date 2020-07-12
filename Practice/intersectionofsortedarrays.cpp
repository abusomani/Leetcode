class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_map<int, int> A, B;
        int N = nums1.size(), M = nums2.size();
        for (int i = 0; i < N; i++)
            A[nums1[i]]++;
        for (int i = 0; i < M; i++)
            B[nums2[i]]++;

        if (A.size() <= B.size())
        {
            for (unordered_map<int, int>::iterator it = A.begin();
                 it != A.end(); it++)
            {

                pair<int, int> P = *it;
                if (B.find(P.first) != B.end())
                    result.push_back(P.first);
            }
        }

        else
        {
            for (unordered_map<int, int>::iterator it = B.begin();
                 it != B.end(); it++)
            {
                pair<int, int> P = *it;
                if (A.find(P.first) != A.end())
                    result.push_back(P.first);
            }
        }
        return result;
    }
};
class Solution
{
public:
    // implementation of lower_bound
    int lower(vector<int> &V, int X)
    {
        int l = 0, r = V.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (V[mid] >= X)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> findClosestElements(vector<int> &V, int k, int x)
    {
        int N = V.size(), idx = lower(V, x); //lower_bound(V.begin(), V.end(), x) - V.begin();
        int left = max(0, idx - k), right = min(N - 1, idx + k - 1);
        while (right - left + 1 > k)
        {
            if (abs(x - V[left]) > abs(x - V[right]))
                left++;
            else
                right--;
        }

        return vector<int>(V.begin() + left, V.begin() + right + 1);
    }
};
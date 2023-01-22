class Solution
{
public:
    static int dist(const vector<int> &A)
    {
        return (A[0] * A[0] + A[1] * A[1]);
    }
    struct compare
    {
        bool operator()(const vector<int> &A, const vector<int> &B)
        {
            return dist(A) < dist(B);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<vector<int>, vector<vector<int>>, compare> PQ;
        for (auto &point : points)
        {
            PQ.push(point);
            if (PQ.size() > K)
                PQ.pop();
        }
        vector<vector<int>> result;
        while (!PQ.empty())
            result.push_back(PQ.top()), PQ.pop();

        return result;
    }
    int partition(vector<vector<int>> &A, int l, int r)
    {
        int i = l;
        for (int k = l + 1; k <= r; k++)
            if (dist(A[k]) < dist(A[l]))
                swap(A[k], A[++i]);
        swap(A[i], A[l]);
        return i;
    }
    vector<vector<int>> kClosestOptimal(vector<vector<int>> &points, int K)
    {
        int l = 0, N = points.size(), r = N - 1;
        while (l <= r)
        {
            int mid = partition(points, l, r);
            if (mid == K)
                break;
            else if (mid < K)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
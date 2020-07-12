typedef long long ll;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        int N = points.size(), l = 0, r = N - 1;
        while (l <= r)
        {
            int mid = partition(points, l, r);
            if (mid == K)
                break;
            if (mid < K)
                l = mid + 1;
            else
                r = mid - 1;
        }
        points.resize(K);
        return points;
    }

    int partition(vector<vector<int>> &points, int l, int r)
    {
        int i = l;
        for (int j = i + 1; j <= r; j++)
            if (dist(points[j]) < dist(points[l]))
                swap(points[j], points[++i]);

        swap(points[i], points[l]);
        return i;
    }

    ll dist(vector<int> &a)
    {
        return (a[0] * a[0] + a[1] * a[1]);
    }
};
class Solution
{
public:
    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes)
    {
        // bucket sort
        vector<vector<pair<int, int>>> buckets(2001);
        int N = workers.size(), M = bikes.size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[d].push_back({i, j});
            }

        vector<int> res(N);
        vector<bool> assignedWorker(N, false), assignedBike(M, false);
        for (int d = 0; d <= 2000; d++)
        {
            for (int i = 0; i < buckets[d].size(); i++)
            {
                pair<int, int> P = buckets[d][i];
                if (!assignedWorker[P.first] and !assignedBike[P.second])
                {
                    assignedWorker[P.first] = true;
                    assignedBike[P.second] = true;
                    res[P.first] = P.second;
                }
            }
        }
        return res;
    }
};
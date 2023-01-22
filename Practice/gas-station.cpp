class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        const int N = gas.size();
        int total = 0, starting = 0;
        for (int i = 0; i < N; i++)
            total += gas[i] - cost[i];

        if (total < 0) // if net total is negative, no possible way
            return -1;

        total = 0;
        for (int i = 0; i < N; i++)
        {
            total += gas[i] - cost[i];
            if (total < 0) // cant reach till here from any station, so lets have i+1 as starting point
                starting = i + 1, total = 0;
        }
        return starting;
    }
};
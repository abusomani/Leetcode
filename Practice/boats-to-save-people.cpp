class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int cnt = 0, N = people.size(), i = 0, j = N - 1;
        while (i <= j)
        {
            int val = people[i] + people[j];
            if (val > limit)
                cnt++, j--;
            else
                cnt++, i++, j--;
        }
        return cnt;
    }
};
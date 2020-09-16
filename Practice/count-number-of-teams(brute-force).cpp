class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int N = rating.size(), ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                for (int k = j + 1; k < N; k++)
                    if ((rating[i] > rating[j] and rating[j] > rating[k]) or (rating[i] < rating[j] and rating[j] < rating[k]))
                        ans++;

        return ans;
    }
};
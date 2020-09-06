// Time complexity => O(sqrt(candies))
class Solution
{
public:
    vector<int> distributeCandies(int candies, int N)
    {
        vector<int> people(N, 0);
        int i = 0, to_give = 1;
        while (candies >= 0)
        {
            people[i++] += min(candies, to_give);
            candies -= to_give;
            to_give++;
            i %= N;
        }
        return people;
    }
};
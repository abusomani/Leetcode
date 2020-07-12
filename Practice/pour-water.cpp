/*
Water first drops at index K and rests on top of the highest terrain or water at that index. 
Then, it flows according to the following rules:

1. If the droplet would eventually fall by moving left, then move left.
2. Otherwise, if the droplet would eventually fall by moving right, then move right.
3. Otherwise, rise at it's current position.
*/
class Solution
{
public:
    vector<int> pourWater(vector<int> &heights, int V, int K)
    {
        const int N = heights.size();
        while (V--)
        {
            int j = K;
            for (int i = K - 1; i >= 0; i--)
            {
                if (heights[i] > heights[j])
                    break; // not going left
                else if (heights[i] < heights[j])
                    j = i; // increase this index
            }
            if (j == K) // nothing on left
            {
                for (int i = K + 1; i < N; i++)
                {
                    if (heights[i] > heights[j])
                        break; // not going left
                    else if (heights[i] < heights[j])
                        j = i; // increase this index
                }
            }
            heights[j]++;
        }

        return heights;
    }
};
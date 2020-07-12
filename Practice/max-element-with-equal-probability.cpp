class Solution
{
public:
    int find_maxIndex(vector<int> a)
    {
        int count = 1;
        int maxElement = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == maxElement)
                count++;
            else if (a[i] > maxElement)
            {
                count = 1;
                maxElement = a[i];
            }
        }
        int occurrence = rand() % count + 1; // ( xth occurence would be picked)
        int occur = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == maxElement)
            {
                occur++;
                if (occur == occurrence)
                    return i;
            }
        }
    }
};
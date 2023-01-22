class Solution
{
public:
    vector<char> geneType = {'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> bankSet(bank.begin(), bank.end()), beginSet, endSet;

        if (!bankSet.count(end)) // is not valid
            return -1;

        bankSet.insert(start); // for visited purpose
        beginSet.insert(start);
        endSet.insert(end);

        int ans = 0;
        while (!beginSet.empty() and !endSet.empty())
        {
            if (beginSet.size() > endSet.size())
            {
                unordered_set<string> tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }

            unordered_set<string> newSet;
            for (auto gene : beginSet)
            {
                bankSet.erase(gene); // remove the visited one

                for (int i = 0; i < gene.size(); i++)
                {
                    string orig = gene;
                    for (int j = 0; j < 4; j++)
                    {
                        orig[i] = geneType[j];

                        if (endSet.count(orig)) // found
                            return ans + 1;

                        if (!bankSet.count(orig)) // not valid
                            continue;

                        newSet.insert(orig);
                    }
                }
            }

            beginSet = newSet; // this becomes the next level
            ans++;
        }

        return -1;
    }
};
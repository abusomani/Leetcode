class Solution
{
private:
    map<string, multiset<string>> targets; // an airport can have multiple same airports, map for having keys sorted and multiset for sorted values
    vector<string> route;

public:
    // go on visiting deep until you get stuck, when you get stuck add that to the path and retrace back
    void visit(string source)
    {
        while (targets[source].size())
        {
            string next = *targets[source].begin();
            targets[source].erase(targets[source].begin());
            visit(next);
        }
        route.push_back(source);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
        {
            targets[ticket[0]].insert(ticket[1]);
        }
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};
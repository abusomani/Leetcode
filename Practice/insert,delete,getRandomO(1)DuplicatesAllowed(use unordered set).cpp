class RandomizedCollection
{
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        V.emplace_back(val);
        Mp[val].insert(V.size() - 1);
        return Mp[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (Mp.find(val) == Mp.end())
            return false;
        auto it = Mp.find(val);
        auto free_pos = *it->second.begin();
        it->second.erase(it->second.begin());
        V[free_pos] = V.back();
        Mp[V.back()].insert(free_pos);    // this would be inserted at free pos
        Mp[V.back()].erase(V.size() - 1); // remove the last occurence
        V.pop_back();
        if (it->second.size() == 0)
            Mp.erase(it);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return V[rand() % (V.size())];
    }

private:
    vector<int> V;                             // elements
    unordered_map<int, unordered_set<int>> Mp; // element and the vector of occured indices
};

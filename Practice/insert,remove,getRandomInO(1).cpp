class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (Mp.find(val) != Mp.end())
            return false;
        V.emplace_back(val);
        Mp[val] = V.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (Mp.find(val) == Mp.end())
            return false;
        int lastNum = V.back();
        Mp[lastNum] = Mp[val]; // set index of lastNum as the present one
        V[Mp[val]] = lastNum;
        Mp.erase(val);
        V.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return V[rand() % (V.size())];
    }

private:
    vector<int> V;              // elements
    unordered_map<int, int> Mp; // element and their last inserted index
};

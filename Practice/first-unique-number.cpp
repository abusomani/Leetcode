class FirstUnique
{
private:
    list<int> unique;
    unordered_map<int, list<int>::iterator> number;
    unordered_set<int> duplicate;

public:
    FirstUnique(vector<int> &nums)
    {
        for (auto &num : nums)
            add(num);
    }

    int showFirstUnique()
    {
        return unique.size() > 0 ? unique.front() : -1;
    }

    void add(int num)
    {
        if (duplicate.count(num))
            return;
        if (number.count(num))
        {
            duplicate.insert(num);     // mark duplicate
            unique.erase(number[num]); // remove from unique list
            return;
        }
        unique.push_back(num);
        number[num] = --unique.end();
    }
};
class PhoneDirectory
{
private:
    unordered_set<int> available;

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
    {
        for (int i = 0; i < maxNumbers; i++)
            available.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get()
    {
        if (!available.empty())
        {
            int val = *available.begin();
            available.erase(val);
            return val;
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number)
    {
        return available.find(number) != available.end();
    }

    /** Recycle or release a number. */
    void release(int number)
    {
        available.insert(number);
    }
};

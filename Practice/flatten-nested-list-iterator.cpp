/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
private:
    stack<NestedInteger> St;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int N = nestedList.size();
        for (int i = N - 1; i >= 0; i--)
            St.push(nestedList[i]);
    }
    void flatten()
    {
        // While is for cases like : [[][][-1]] and [[]]
        while (!St.empty() and !St.top().isInteger())
        {
            vector<NestedInteger> V = St.top().getList();
            St.pop();
            int N = V.size();
            for (int i = N - 1; i >= 0; i--)
                St.push(V[i]);
        }
    }
    int next()
    {
        hasNext();
        int val = St.top().getInteger();
        St.pop();
        return val;
    }

    bool hasNext()
    {
        if (St.size())
            flatten();
        return St.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
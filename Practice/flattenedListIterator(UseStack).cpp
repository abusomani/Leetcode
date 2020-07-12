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
//[[[1]], 2, 3]
class NestedIterator
{
private:
    stack<NestedInteger> nodes;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int N = nestedList.size();
        for (int i = N - 1; i >= 0; i--)
            nodes.push(nestedList[i]);
    }

    int next()
    {
        hasNext();
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }

    // deserialize a list when called, unfolding when called
    bool hasNext()
    {
        while (!nodes.empty())
        {
            NestedInteger node = nodes.top();
            if (node.isInteger())
                return true;
            nodes.pop(); // it is a list, push all values inside stack

            vector<NestedInteger> lst = node.getList();
            for (int i = lst.size() - 1; i >= 0; i--)
                nodes.push(lst[i]);
        }

        return false;
    }
};
//[[[1]], 2, 3]

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
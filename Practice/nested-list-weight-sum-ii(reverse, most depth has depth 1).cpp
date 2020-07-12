/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
private:
    int maxDepth = 0;

public:
    void getDepth(vector<NestedInteger> &nestedList, int depth)
    {
        for (auto n : nestedList)
            if (!n.isInteger())
                getDepth(n.getList(), depth + 1);

        maxDepth = max(maxDepth, depth);
    }
    int depthSum(vector<NestedInteger> &nestedList, int depth)
    {
        int ans = 0;
        for (auto n : nestedList)
        {
            if (n.isInteger())
                ans += depth * n.getInteger();
            else
                ans += depthSum(n.getList(), depth - 1);
        }
        return ans;
    }
    int depthSumInverse(vector<NestedInteger> &nestedList)
    {
        getDepth(nestedList, 1);
        return depthSum(nestedList, maxDepth);
    }
};
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

/*
The idea is to deduct number depth - level times.
For example, 1x + 2y + 3z = (3 + 1) * (x + y + z) - (3x + 2y + z);
*/
class Solution
{
private:
    int flatSum = 0;
    int maxDepth = 1;

public:
    int depthSum(vector<NestedInteger> &nestedList, int depth = 1)
    {
        int sum = 0;
        for (auto n : nestedList)
        {
            if (n.isInteger())
            {
                flatSum += n.getInteger();
                sum += n.getInteger() * depth;
            }
            else
            {
                sum += depthSum(n.getList(), depth + 1);
            }
        }
        maxDepth = max(maxDepth, depth);
        return sum;
    }
    int depthSumInverse(vector<NestedInteger> &nestedList)
    {
        int depthsum = depthSum(nestedList, 1);
        return flatSum * (maxDepth + 1) - depthsum;
    }
};
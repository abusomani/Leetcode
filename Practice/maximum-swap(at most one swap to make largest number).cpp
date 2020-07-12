/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.

Logic : 
Start from backwards and track the max digit and its idx.
Whenever we get a digit smaller than maxDigit, that makes a probable candidate for swap. Record its value
*/
class Solution
{
public:
    int maximumSwap(int num)
    {
        string numstr = to_string(num);

        int maxidx = -1;
        int maxdigit = -1;
        int leftidx = -1;
        int rightidx = -1;

        for (int i = numstr.size() - 1; i >= 0; --i)
        {
            // current digit is the largest by far
            if (numstr[i] > maxdigit)
            {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more
            // such situation on the left side
            if (numstr[i] < maxdigit)
            {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1)
            return num;

        swap(numstr[leftidx], numstr[rightidx]);

        return stoi(numstr);
    }
};
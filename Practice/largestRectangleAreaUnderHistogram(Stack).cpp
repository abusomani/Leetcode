class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int N = heights.size(), area = 0, ans = 0;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            if (St.empty() or heights[i] >= heights[St.top()]) // keep pushing if current height >= top
            {
                St.push(i);
                continue;
            }
            while (!St.empty() and heights[St.top()] >= heights[i])
            {
                int height = heights[St.top()];
                St.pop();
                int width = (St.empty()) ? i : i - St.top() - 1;
                ans = max(ans, height * width);
            }
            St.push(i);
        }

        while (!St.empty())
        {
            int height = heights[St.top()];
            St.pop();
            int width = (St.empty()) ? N : N - St.top() - 1;
            ans = max(ans, height * width);
        }

        return ans;
    }
};
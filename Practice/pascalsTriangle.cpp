class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        if (numRows == 0)
            return triangle;

        triangle.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            int prevSize = triangle.back().size();
            vector<int> curr;
            for (int j = 0; j <= prevSize; j++)
            {
                if (j == 0 or j == prevSize)
                    curr.push_back(1);
                else
                    curr.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
            if (curr.size())
                triangle.push_back(curr);
        }

        return triangle;
    }
};
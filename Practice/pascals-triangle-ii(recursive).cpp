class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};

        vector<int> prevRow = getRow(rowIndex - 1);
        vector<int> newRow;
        for (int i = 0; i <= prevRow.size(); i++)
        {
            if (i == 0 or i == prevRow.size())
                newRow.push_back(1);
            else
                newRow.push_back(prevRow[i] + prevRow[i - 1]);
        }
        return newRow;
    }
};
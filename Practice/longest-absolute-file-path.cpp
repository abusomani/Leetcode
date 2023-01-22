class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stringstream ss(input);
        string curr;
        unordered_map<int, int> Mp;
        int result = 0;
        while (getline(ss, curr, '\n'))
        {
            auto depth = curr.find_last_of("\t");
            string name = depth == string::npos ? curr : curr.substr(depth + 1);

            // means file name
            if (name.find(".") != string::npos)
            {
                result = max(result, Mp[depth - 1] + (int)name.size());
            }
            else
                Mp[depth] = Mp[depth - 1] + name.size() + 1;
        }
        return result;
    }
};
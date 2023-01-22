class Solution
{
public:
    string reorganizeString(string S)
    {
        unordered_map<char, int> Mp;
        for (auto &c : S)
            Mp[c]++;

        // push into heap, {count, char}
        priority_queue<pair<int, char>> PQ;
        for (auto it : Mp)
            PQ.push({it.second, it.first});

        // delimiter for ease
        string result = "#";
        while (!PQ.empty())
        {
            // take out front
            pair<int, char> A = PQ.top();
            PQ.pop();
            // if the last pushed is same as present
            if (result.back() == A.second)
            {
                // if no more in heap, not possible
                if (PQ.empty())
                    return "";
                // pop out from top again
                pair<int, char> B = PQ.top();
                PQ.pop();
                // push the present one
                PQ.push(A);
                A = B;
            }
            // common operations
            result += A.second;
            A.first--;
            // push back in heap only if count > 0
            if (A.first > 0)
                PQ.push({A.first, A.second});
        }
        return result.substr(1);
    }
};
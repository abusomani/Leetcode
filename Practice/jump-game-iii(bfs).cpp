class Solution
{
private:
    unordered_set<int> visited;
    bool isValidIndex(int idx, int N)
    {
        return idx >= 0 and idx < N and !visited.count(idx);
    }
    void push(int idx, queue<int> &Q)
    {
        visited.insert(idx);
        Q.push(idx);
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        queue<int> Q;
        Q.push(start);
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                int idx = Q.front();
                Q.pop();
                if (arr[idx] == 0)
                    return true;
                visited.insert(idx);
                if (isValidIndex(idx + arr[idx], arr.size()))
                    push(idx + arr[idx], Q);
                if (isValidIndex(idx - arr[idx], arr.size()))
                    push(idx - arr[idx], Q);
            }
        }
        return false;
    }
};
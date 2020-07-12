class Solution
{
public:
    bool compare(deque<int> &Dq, int num, int X)
    {
        if (abs(X - Dq.front()) > abs(X - num))
            return true;
        return false;
    }
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        deque<int> Dq;
        int N = arr.size();
        for (int i = 0; i < N; i++)
        {
            if (Dq.size() < k) // blindly push to deque
                Dq.push_back(arr[i]);
            else
            {
                // until window size is >= k, and front is pop worthy keep popping
                while (!Dq.empty() and Dq.size() >= k and compare(Dq, arr[i], x))
                    Dq.pop_front();
                Dq.push_back(arr[i]); // push present element
            }
        }
        vector<int> result;
        for (int i = 0; i < k; i++) // take first k elements
            result.push_back(Dq.front()), Dq.pop_front();

        return result;
    }
};
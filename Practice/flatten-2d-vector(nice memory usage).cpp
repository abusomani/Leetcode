/*
Time complexity:
Constructor: O(1)
next() / hasNext(): O(V/N) or O(1)
Space complexity : O(1).
*/
class Vector2D
{
private:
    int inner = 0, outer = 0, N;
    vector<vector<int>> A;

public:
    Vector2D(vector<vector<int>> &v)
    {
        A = v;
        inner = 0, outer = 0, N = A.size();
    }

    int next()
    {
        hasNext();
        return A[outer][inner++];
    }

    bool hasNext()
    {
        while (outer < N and inner >= A[outer].size())
            outer++, inner = 0;

        return outer < N;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class MinStack
{
public:
    MinStack()
    {
        Res.clear();
    }

    void push(int x)
    {
        if (Res.empty())
            Res.emplace_back(make_pair(x, x));
        else
            Res.emplace_back(make_pair(x, min(getMin(), x)));
    }

    void pop()
    {
        Res.pop_back();
    }

    int top()
    {
        return Res.back().first;
    }

    int getMin()
    {
        return Res.back().second;
    }

private:
    vector<pair<int, int>> Res;
};

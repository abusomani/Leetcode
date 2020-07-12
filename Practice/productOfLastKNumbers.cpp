class ProductOfNumbers
{
public:
    vector<int> result;
    ProductOfNumbers()
    {
        result = {1};
    }

    void add(int num)
    {
        if (num)
        {
            result.push_back(result.back() * num);
        }
        else
        {
            result = {1};
        }
    }

    int getProduct(int k)
    {
        int n = result.size();
        return k < n ? result[n - 1] / result[n - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
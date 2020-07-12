class Solution
{
public:
    //High is not included so < high is the case.
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high - 1];
        int start = low - 1;

        for (int i = low; i < high; i++)
        {
            if (nums[i] >= pivot)
                continue;
            swap(nums[++start], nums[i]);
        }

        swap(nums[++start], nums[high - 1]);
        return start;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        // 1 element is already sorted
        if (low < high)
        {
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot);
            quickSort(nums, pivot + 1, high);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums;

        quickSort(nums, 0, nums.size());
        return nums;
    }
};
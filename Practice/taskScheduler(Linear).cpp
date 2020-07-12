/*
[A,A,A,A,B,B,B,B,C,C,D]
3
ABCD
ABC-
AB--
AB
OUTPUT: 14

https://leetcode.com/problems/task-scheduler/Figures/621_Task_Scheduler_new.PNG
*/
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int cnt[26] = {0}, mx_val = -1, mx_cnt = 0, N = tasks.size();
        for (int i = 0; i < N; i++)
        {
            int idx = tasks[i] - 'A';
            cnt[idx]++;
            if (cnt[idx] > mx_val)
            {
                mx_val = cnt[idx];
                mx_cnt = 1;
            }
            else if (cnt[idx] == mx_val)
                mx_cnt++;
        }

        int numberOfSlots = (mx_val - 1);
        int eachPartCount = n - (mx_cnt - 1); // excluding first max
        int availableSlots = numberOfSlots * eachPartCount;
        int totalTasksApartFromMax = N - (mx_val * mx_cnt);
        int idles = max(0, availableSlots - totalTasksApartFromMax);

        return N + idles;
    }
};
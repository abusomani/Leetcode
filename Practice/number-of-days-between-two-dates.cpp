struct Calendar
{
    int year;
    int month;
    int day;
};
class Solution
{
public:
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Calendar processDate(string str)
    {
        string tmp;
        stringstream ss(str);
        vector<string> res;
        while (getline(ss, tmp, '-'))
            res.push_back(tmp);

        return {stoi(res[0]), stoi(res[1]), stoi(res[2])};
    }
    bool isLeapYear(int year)
    {
        if (year % 100 == 0)
            return year % 400 == 0;
        return year % 4 == 0;
    }
    int getDays(int year, int month, int day)
    {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        for (int i = 1971; i < year; i++)
            res += 365 + isLeapYear(i);
        for (int i = 1; i < month; i++)
            res += days[i] + ((i == 2 and isLeapYear(year)) ? 1 : 0);
        return res + day;
    }
    int daysBetweenDates1(string date1, string date2)
    {
        if (date1 > date2)
            return daysBetweenDates(date2, date1);
        Calendar start = processDate(date1), end = processDate(date2);
        if (start.year == end.year and start.month == end.month)
            return end.day - start.day;
        return getDays(end.year, end.month, end.day) - getDays(start.year, start.month, start.day);
    }
    int daysBetweenDates(string date1, string date2)
    {
        if (date1 > date2)
            return daysBetweenDates(date2, date1);
        Calendar start = processDate(date1), end = processDate(date2);
        if (start.year == end.year and start.month == end.month)
            return end.day - start.day;
        int ans = days[start.month] - start.day + min(days[end.month], end.day);
        if (start.month == 2 and !isLeapYear(start.year))
            ans--;

        int l = start.year, r = end.year, p, q;
        if (start.month == 12)
        {
            l++;
            p = 1;
        }
        else
            p = start.month + 1;

        if (end.month == 1)
        {
            r--;
            q = 12;
        }
        else
            q = end.month - 1;

        while (l <= r)
        {
            if (l == r and p > q)
                break;

            if (p == 2 and !isLeapYear(l))
                ans--;

            ans += days[p++];
            if (p == 13)
            {
                l++;
                p = 1;
            }
        }
        return ans;
    }
};
class Solution
{
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num)
    {
        string result = dfs(num);
        return result.empty() ? "Zero" : result.substr(1);
    }
    string dfs(int num)
    {
        if (num >= 1000000000)
            return dfs(num / 1000000000) + " Billion" + dfs(num % 1000000000);
        if (num >= 1000000)
            return dfs(num / 1000000) + " Million" + dfs(num % 1000000);
        if (num >= 1000)
            return dfs(num / 1000) + " Thousand" + dfs(num % 1000);
        if (num >= 100)
            return dfs(num / 100) + " Hundred" + dfs(num % 100);
        if (num >= 20)
            return " " + tens[num / 10] + dfs(num % 10);
        if (num >= 1)
            return " " + ones[num];
        return ""; // For zero
    }
};
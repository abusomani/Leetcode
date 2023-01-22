class Solution
{
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num)
    {
        return num ? toWords(num).substr(1) : "Zero";
    }
    string toWords(int num)
    {
        if (num >= 1000000000)
            return toWords(num / 1000000000) + " Billion" + toWords(num % 1000000000);
        if (num >= 1000000)
            return toWords(num / 1000000) + " Million" + toWords(num % 1000000);
        if (num >= 1000)
            return toWords(num / 1000) + " Thousand" + toWords(num % 1000);
        if (num >= 100)
            return toWords(num / 100) + " Hundred" + toWords(num % 100);
        if (num >= 20)
            return " " + tens[num / 10] + toWords(num % 10);
        if (num >= 1)
            return " " + ones[num];
        return "";
    }
};
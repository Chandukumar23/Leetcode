class Solution {
public:
    int findNthDigit(int n) {
        long long digitLen = 1;
        long long count = 9;
        long long start = 1;
        while (n > digitLen * count) {
            n -= digitLen * count;
            digitLen++;
            count *= 10;
            start *= 10;
        }
        long long number = start + (n - 1) / digitLen;
        string s = to_string(number);
        return s[(n - 1) % digitLen] - '0';
    }
};

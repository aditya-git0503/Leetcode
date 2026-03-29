class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long half = power(x, n / 2);
        long long result = (half * half) % mod;

        if (n % 2) {
            result = (result * x) % mod;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long a = power(5, evenCount);
        long long b = power(4, oddCount);

        return (a * b) % mod;
    }
};
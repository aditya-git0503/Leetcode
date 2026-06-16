class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                len++;
            } else if (ch == '#') {
                len = len * 2;
            } else if (ch == '*') {
                if (len > 0)
                    len--;
            }
        }

        if (k < 0 || k >= len)
            return '.';

        k = k + 1;

        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == '#') {
                if (k > len / 2)
                    k -= len / 2;
                len /= 2;
            } else if (ch == '%') {
                k = len - k + 1;
            } else if (ch == '*') {
                len++;
            } else if (ch >= 'a' && ch <= 'z') {
                if (k == len)
                    return ch;
                len--;
            }
        }
        return '.';
    }
};
class Solution {
public:
    bool check(string s) {
        for (char ch : s) {
            int x = (int)ch;
            if (x % 2 != 0) {
                return true;
            }
        }
        return false;
    }

    string largestOddNumber(string num) {
        if (check(num) == false) {
            return "";
        }

        int p, q;
        int l = num.length();
        q = l - 1;

        for (int i = l - 1; i >= 0; i--) {
            int x = (int)num[i];
            if (x % 2 != 0) {
                q = i;
                break;
            }
        }

        return num.substr(0, q + 1);
    }
};
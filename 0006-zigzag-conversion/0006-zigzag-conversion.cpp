class Solution {
public:
    string convert(string s, int rows) {
        if(rows == 1){
            return s;
        }

        vector<string> rowsStr(rows);

        int r = 0;
        bool goingDown = false;

        for (char c : s) {
            rowsStr[r] += c;

            if (r == 0 || r == rows - 1)
                goingDown = !goingDown;

            r += goingDown ? 1 : -1;
        }

        string ans;
        for (string& row : rowsStr)
            ans += row;

        return ans;
    }
};
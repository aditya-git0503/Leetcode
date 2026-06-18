class Solution {
public:
    void help(int index, int n, int k, string& s, int cost, char prev,
              vector<string>& result) {
        if (index == n) {
            result.push_back(s);
            return;
        }

        s += '0';
        help(index + 1, n, k, s, cost, '0', result);
        s.pop_back();

        if (prev != '1' && cost + index <= k) {
            s += '1';
            help(index + 1, n, k, s, cost + index, '1', result);
            s.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        string s = "";
        help(0, n, k, s, 0, '0', result);
        return result;
    }
};
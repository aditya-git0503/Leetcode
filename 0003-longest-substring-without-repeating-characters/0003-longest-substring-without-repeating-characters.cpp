class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int left = 0;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            left = max(left, last[s[i]] + 1);
            last[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
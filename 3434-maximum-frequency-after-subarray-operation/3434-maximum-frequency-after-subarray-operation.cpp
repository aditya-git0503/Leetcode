class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_set<int> values(nums.begin(), nums.end());

        int base = 0;
        for (int i : nums) {
            if (i == k) {
                base++;
            }
        }
        int ans = base;
        for (int t : values) {
            if (t == k) {
                continue;
            }

            int curr = 0;
            int best = 0;

            for (int i : nums) {
                int val;
                if (t == i) {
                    val = 1;
                } else if (i == k) {
                    val = -1;
                } else {
                    val = 0;
                }

                curr = max(val, curr + val);
                best = max(best, curr);
                ans = max(ans, base + best);
            }
        }
        return ans;
    }
};
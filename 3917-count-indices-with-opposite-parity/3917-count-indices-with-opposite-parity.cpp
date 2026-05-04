class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int val = 0;
            for (int j = i + 1; j < n; j++) {
                if (((nums[i] & 1) && !(nums[j] & 1)) ||
                    ((nums[j] & 1) && !(nums[i] & 1))) {
                        val++;
                }
            }
            ans[i] = val;
        }
        return ans;
    }
};
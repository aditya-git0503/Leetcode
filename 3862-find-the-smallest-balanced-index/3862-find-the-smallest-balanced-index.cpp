class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();

        if (n == 1) {
            return -1;
        }

        vector<long long> sums(n, 0);
        sums[0] = 0;
        vector<long long> prod(n, 0);

        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        prod[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (prod[i + 1] > LLONG_MAX / nums[i + 1]) {
                prod[i] = LLONG_MAX;
            } else {
                prod[i] = prod[i + 1] * nums[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (sums[i] == prod[i]) {
                return i;
            }
        }
        return -1;
    }
};
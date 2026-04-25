class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (auto it : mpp) {
            vector<int> v = it.second;
            int k = v.size();

            vector<long long> prefix(k);
            prefix[0] = v[0];

            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)v[i] * i - prefix[i - 1];
                }

                if (i < k - 1) {
                    right = (prefix[k - 1] - prefix[i]) -
                            (long long)v[i] * (k - i - 1);
                }

                ans[v[i]] = left + right;
            }
        }
        return ans;
    }
};
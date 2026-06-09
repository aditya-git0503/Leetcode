class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        unordered_map<int, int> mpp;
        vector<int> ans;

        for (int i : nums) {
            mpp[i]++;
        }

        for (auto it : mpp) {
            bucket[it.second].push_back(it.first);
        }

        for (int freq = n; freq >= 1; freq--) {
            for (int num : bucket[freq]) {
                ans.push_back(num);
                k--;

                if (k == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
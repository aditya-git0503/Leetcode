class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // init

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(target - sum) < abs(target - closestSum)) {
                        closestSum = sum;
                    }
                }
            }
        }
        return closestSum;
    }
};
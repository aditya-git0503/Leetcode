class Solution {
public:

    int lb(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = high + (low-high)/2;
            if(nums[mid] >= target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int ub(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = high + (low-high)/2;
            if(nums[mid] > target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lb(nums, target);
        int n = nums.size();
        if(l == n || nums[l] != target){
            return {-1, -1};
        }

        else{
            int u = ub(nums, target);
            return {l, u-1};
        }
    }
};
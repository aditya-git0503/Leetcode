class Solution {
public:

    int f(vector<int>& nums, int target, int n){
        int first = -1;
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = high + (low - high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return first;
    }

    int l(vector<int>& nums, int n, int target){
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low <= high){
            int mid = high + (low - high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int n = nums.size();
        int a1 = f(nums, target, n);
        int a2 = l(nums, n, target);
        return {a1,a2};
    }
};
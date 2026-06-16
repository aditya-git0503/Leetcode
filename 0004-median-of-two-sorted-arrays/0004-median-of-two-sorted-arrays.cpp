class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (n1 + n2) / 2 - i;

            int nums1_left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right = (i == n1) ? INT_MAX : nums1[i];
            int nums2_left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right = (j == n2) ? INT_MAX : nums2[j];

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if ((n1 + n2) % 2 == 1) {
                    return min(nums1_right, nums2_right);
                } else {
                    return (max(nums1_left, nums2_left) +
                            min(nums1_right, nums2_right)) /
                           2.0;
                }
            } else if (nums1_left > nums2_right) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};
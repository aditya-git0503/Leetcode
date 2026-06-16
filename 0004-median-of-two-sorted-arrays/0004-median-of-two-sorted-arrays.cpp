class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> final;

        while (l < n1 && r < n2) {
            if (nums1[l] <= nums2[r]) {
                final.push_back(nums1[l++]);
            } else {
                final.push_back(nums2[r++]);
            }
        }

        while (l < n1)
            final.push_back(nums1[l++]);
        while (r < n2)
            final.push_back(nums2[r++]);

        int n3 = final.size();
        if (n3 & 1) {
            return (double)(final[n3 / 2]);
        } else {
            return (final[n3 / 2 - 1] + final[n3 / 2]) / 2.0;
        }
    }
};
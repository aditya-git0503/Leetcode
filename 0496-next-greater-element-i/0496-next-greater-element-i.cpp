class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        for (int i : nums1) {
            int j;
            int temp = -1;
            for (j = 0; j < n2; j++) {
                if (nums2[j] == i) {
                    break;
                }
            }
            if (j == n2 - 1) {
                ans.push_back(-1);
                continue;
            } else {
                for (; j < n2; j++) {
                    if (nums2[j] > i){
                        temp = nums2[j];
                        break;
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;

        for(int i=0; i<n1; i++){
            int l = i;
            int h = n2-1;
            while(l <= h){
                int mid = l + (h - l)/2;
                if(nums1[i] <= nums2[mid]){
                    ans = max(ans, mid-i);
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int l1 = 0, l2 = 0;
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        l1 = arr1[0];
        l2 = arr2[0];
        int n = nums.size();

        for(int i=2; i<n; i++){
            if(l1 > l2){
                l1 = nums[i];
                arr1.push_back(nums[i]);
            }
            else{
                l2 = nums[i];
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
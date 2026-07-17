class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> mx(n);
        mx[0] = nums[0];
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            mx[i] = max(mx[i-1], nums[i]);
            pref[i] = gcd(mx[i], nums[i]);
        }
        sort(pref.begin(), pref.end());
        n = pref.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            int x = gcd(pref[l], pref[r]);
            sum += x;
            l++;
            r--;
        }
        return sum;
    }
};
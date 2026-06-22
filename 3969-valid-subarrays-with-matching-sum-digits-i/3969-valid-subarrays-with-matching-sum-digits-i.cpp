class Solution {
public:

    bool check(long long sum, int x){
        int last = 0;
        
        last = sum % 10;
        if(last != x){
            return false;
        }

        while(sum >= 10){
            sum /= 10;
        }
        if(sum != x){
            return false;
        }
        return true;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n;i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(check(sum, x)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
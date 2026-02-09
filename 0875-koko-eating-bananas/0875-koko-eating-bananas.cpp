class Solution {
public:

    long long check(vector<int>& piles, int k, int n){
        long long ans = 0;
        for(int i : piles){
            ans += ceil((double)i / (double)k);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        int l = 1;
        int high = piles[0];
        int n = piles.size();
        int ans = 0;
        for(int i : piles){
            if(i > high){
                high = i;
            }
        }

        while(l <= high){
            int m = l + (high - l)/2;
            long long val = check(piles, m, n);
            if(val <= h){
                ans = m;
                high = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};
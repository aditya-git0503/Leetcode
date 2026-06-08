class Solution {
public:
    bool check(vector<int> piles, int h, int k) {
        long long total = 0;
        for (int i : piles) {
            total += (i + k - 1)/k;
        }

        if (total <= h) {
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        int low = 1;
        int high = piles[0];
        int mid = 0;
        int ans = 0;

        for (int i : piles) {
            high = max(high, i);
        }

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (check(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
        }
        return ans;
    }
};
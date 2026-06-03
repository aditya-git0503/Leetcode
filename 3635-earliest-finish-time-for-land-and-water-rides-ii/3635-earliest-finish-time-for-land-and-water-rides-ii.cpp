class Solution {
public:
    int help(vector<int>& firstStart, vector<int>& firstDuration,
             vector<int>& secondStart, vector<int>& secondDuration) {
        int n = firstStart.size();
        int m = secondStart.size();

        vector<pair<int, int>> ride;
        for (int j = 0; j < m; j++) {
            ride.push_back({secondStart[j], secondDuration[j]});
        }
        sort(ride.begin(), ride.end());

        vector<int> suffixMin(m);
        suffixMin[m - 1] = ride[m - 1].first + ride[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            int curr = ride[i].first + ride[i].second;
            suffixMin[i] = min(curr, suffixMin[i + 1]);
        }

        vector<int> prefixMin(m);
        prefixMin[0] = ride[0].second;

        for (int i = 1; i < m; i++) {
            prefixMin[i] = min(ride[i].second, prefixMin[i - 1]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int t = firstStart[i] + firstDuration[i];
            int pos =
                upper_bound(ride.begin(), ride.end(), make_pair(t, INT_MAX)) -
                ride.begin();
            if (pos > 0) {
                ans = min(ans, t + prefixMin[pos - 1]);
            }

            if (pos < m) {
                ans = min(ans, suffixMin[pos]);
            }
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans1 =
            help(landStartTime, landDuration, waterStartTime, waterDuration);

        int ans2 =
            help(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(ans1, ans2);
    }
};
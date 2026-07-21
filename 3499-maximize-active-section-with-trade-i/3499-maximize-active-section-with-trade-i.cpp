class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";
        int n = s.size();
        int ones = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1'){
                ones++;
            }
        }

        vector<pair<char, int>> runs;
        int i = 0;
        while (i < n) {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c) {
                cnt++;
                i++;
            }
            runs.push_back({c, cnt});
        }

        int maxGain = 0;
        for (int j = 0; j + 2 < runs.size(); j++) {
            if (runs[j].first == '0' && runs[j + 1].first == '1' &&
                runs[j + 2].first == '0') {
                maxGain = max(maxGain, runs[j].second + runs[j + 2].second);
            }
        }

        return ones + maxGain;
    }
};
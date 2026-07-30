class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mpp;
        for (char ch : word) {
            mpp[ch]++;
        }

        vector<pair<char,int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        int cost = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            int pos = i / 8 + 1;      
            cost += pos * v[i].second;
        }
        return cost;
    }
};
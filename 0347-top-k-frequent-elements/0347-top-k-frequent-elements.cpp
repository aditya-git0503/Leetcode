class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<pair<int, int>> v;

        for(int i : nums){
            mpp[i]++;
        }

        for(auto it : mpp){
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
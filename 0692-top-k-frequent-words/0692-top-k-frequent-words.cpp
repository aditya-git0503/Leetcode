class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> buckets(n+1);
        unordered_map<string, int> mpp;
        vector<string> ans;

        for(string s : words){
            mpp[s]++;
        }

        for(auto it : mpp){
            buckets[it.second].push_back(it.first);
        }

        for(int i=1; i<=n; i++){
            sort(buckets[i].begin(), buckets[i].end());
        }

        for(int freq=n; freq >= 1; freq--){
            int x = buckets[freq].size();
            for(int j=0; j<x; j++){
                ans.push_back(buckets[freq][j]);
                k--;

                if(k == 0){
                    return ans;
                }
            }
        }
        return ans;
    }
};
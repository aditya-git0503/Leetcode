class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();

        for(int i=0; i<n; i++){
            if(words[i] == target){
                int diff = abs(i - startIndex);
                ans = min(ans, min(diff, n-diff));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
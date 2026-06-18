class Solution {
public:
    bool isBalanced(map<int,int>& freq, map<int, int>& freqCount){
        if(freq.size() == 1) return true;
        if(freqCount.size() != 2) return false;
        
        auto it = freqCount.begin();
        int f1 = it->first; 
        it++;
        int f2 = it->first;
        
        return (f2 == f1*2) || (f1 == f2*2);
    }

    int getLength(vector<int>& nums) {
        int maxLen = 1;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            map<int,int> freq;
            map<int,int> freqCount;
            
            for(int j=i; j<n; j++){
                int val = nums[j];
                
                if(freq[val] > 0){
                    freqCount[freq[val]]--;
                    if(freqCount[freq[val]] == 0) freqCount.erase(freq[val]);
                }
                
                freq[val]++;
                freqCount[freq[val]]++;
                
                if(isBalanced(freq,freqCount)){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};
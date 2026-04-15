class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int l = startIndex;
        int r = startIndex;
        int lenl = 0;
        int lenr = 0;
        int flag = 0;
        int n = words.size();

        for(string s : words){
            if(s == target){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return -1;

        if(words[startIndex] == target)
            return 0;
        
        while(true){
            if(words[l] == target || words[r] == target){
                return min(lenl, lenr);
            }
            else{
                l = (l-1+n) % n;
                lenl++;
                r = (r + 1) % n;
                lenr++;
            }
        }
        return min(lenl, lenr);
    }
};
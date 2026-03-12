class Solution {
public:
    bool rotateString(string s, string goal) {
        int l = s.size();
        string str = s + s;
        for(int i=0; i<= l; i++){
            if(str.substr(i,l) == goal){
                return true;
            }
        }
        return false;
    }
};
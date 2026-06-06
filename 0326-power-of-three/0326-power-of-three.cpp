class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        int x = 1162261467;
        if(x % n){
            return false;
        }
        return true;
    }
};
class Solution {
public:

    int num(int x){
        int ans = 1;
        while(x > 0){
            ans *= (x % 10);
            x /= 10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        for(int i=n; ; i++){
            if((num(i)) % t == 0){
                return i;
            }
        }
        return n;
    }
};
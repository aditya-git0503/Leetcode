class Solution {
public:
    int minCost(int n) {
        int ans = 0;
        int num = n;

        while(num >= 1){
            int a = num - 1;
            ans += a;
            num--;
        }
        return ans;
    }
};
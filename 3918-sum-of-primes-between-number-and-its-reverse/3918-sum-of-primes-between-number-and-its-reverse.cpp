class Solution {
public:
    int reverse(int n){
        int ans = 0;
        while(n){
            ans = ans * 10 + (n % 10);
            n /= 10;
        }
        return ans;
    }

    bool isPrime(int n){
        int val = sqrt(n);
        if(n == 1)
            return false;
        for(int i=2; i<=val; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int l,r;
        int ans = 0;
        l = min(n,reverse(n));
        r = max(n,reverse(n));

        while(l <= r){
            if(isPrime(l)){
                ans += l;
            }
            l++;
        }
        return ans;
    }
};
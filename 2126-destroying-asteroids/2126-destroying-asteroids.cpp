class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = (long long)mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i : asteroids){
            if(i > m){
                return false;
            }
            else{
                m += i;
            }
        }
        return true;
    }
};
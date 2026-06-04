class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;

        for(int i = num1; i <= num2; i++) {
            if(i < 100) continue;

            string s = to_string(i);
            int len = s.size();

            for(int j = 1; j < len - 1; j++) {
                if ((s[j] > s[j-1] && s[j] > s[j+1]) || 
                    (s[j] < s[j-1] && s[j] < s[j+1])) {
                    count++;
                }
            }
        }
        return count;
    }
};
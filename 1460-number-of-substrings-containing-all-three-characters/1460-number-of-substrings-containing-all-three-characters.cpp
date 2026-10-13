class Solution {
private:
   
    int atMost(string s, int most) {
        int n = s.length();
        int l = 0;
        int count = 0;
        unordered_map<char, int> memo;

        for (int r = 0; r < n; r++) {
            memo[s[r]]++;

            
            while (memo.size() > most) {
                memo[s[l]]--;
                if (memo[s[l]] == 0) {
                    memo.erase(s[l]);
                }
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }

public:
    int numberOfSubstrings(string s) {
        return atMost(s, 3) - atMost(s, 2);
    }
};

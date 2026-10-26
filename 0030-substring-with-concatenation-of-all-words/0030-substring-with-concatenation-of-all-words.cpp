class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();

        if (m == 0) return {};

        int k = words[0].length();

        if (n < m * k) return {};

        unordered_map<string, int> memo;

        for (string w : words) {
            memo[w]++;
        }

        vector<int> ans;

        // Try all possible starting offsets.
        for (int offset = 0; offset < k; offset++) {
            int l = offset;
            int total = 0;

            unordered_map<string, int> store;

            for (int r = offset; r + k <= n; r += k) {
                string st = s.substr(r, k);

                // If the current word is invalid,
                // reset the sliding window.
                if (memo.count(st) == 0) {
                    store.clear();
                    total = 0;
                    l = r + k;
                    continue;
                }

                store[st]++;
                total++;

                // Remove excess occurrences of the current word.
                while (store[st] > memo[st]) {
                    string temp = s.substr(l, k);

                    store[temp]--;
                    total--;
                    l += k;
                }

                // A complete concatenation has been found.
                if (total == m) {
                    ans.push_back(l);

                    // Move the left pointer to search for
                    // the next possible concatenation.
                    string temp = s.substr(l, k);

                    store[temp]--;
                    total--;
                    l += k;
                }
            }
        }

        return ans;
    }
};
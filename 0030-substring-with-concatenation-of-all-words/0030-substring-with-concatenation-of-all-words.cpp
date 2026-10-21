class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty()) return ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        if (n < windowLen) return ans;

        unordered_map<string, int> required;

        for (const string& word : words) {
            required[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            int l = offset;
            int count = 0;
            unordered_map<string, int> seen;

            for (int r = offset; r + wordLen <= n; r += wordLen) {
                string word = s.substr(r, wordLen);

                if (required.find(word) == required.end()) {
                    seen.clear();
                    count = 0;
                    l = r + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > required[word]) {
                    string leftWord = s.substr(l, wordLen);
                    seen[leftWord]--;
                    count--;
                    l += wordLen;
                }

                if (count == wordCount) {
                    ans.push_back(l);

                    string leftWord = s.substr(l, wordLen);
                    seen[leftWord]--;
                    count--;
                    l += wordLen;
                }
            }
        }

        return ans;
    }
};
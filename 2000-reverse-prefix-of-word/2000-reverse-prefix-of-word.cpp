class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto idx = word.find(ch);
        if (idx != string::npos) {
            reverse(word.begin(), word.begin() + idx + 1);
        }
        return word;
    }
};

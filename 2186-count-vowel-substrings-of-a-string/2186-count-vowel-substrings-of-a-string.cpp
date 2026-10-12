#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // Helper function to count substrings with AT MOST k DISTINCT vowels
    int atMostKDistinct(string s, int k) {
        int n = s.length();
        int l = 0;
        int count = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < n; r++) {
            freq[s[r]]++;
            
            // Shrink window if distinct vowels exceed k
            while (freq.size() > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
                l++;
            }
            // Add the number of valid substrings ending at 'r'
            count += (r - l + 1);
        }
        return count;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int countVowelSubstrings(string word) {
        int totalCount = 0;
        string currentVowelBlock = "";

        for (char c : word) {
            if (isVowel(c)) {
                currentVowelBlock += c;
            } else {
                // Process the accumulated vowel block before resetting
                if (!currentVowelBlock.empty()) {
                    totalCount += (atMostKDistinct(currentVowelBlock, 5) - atMostKDistinct(currentVowelBlock, 4));
                    currentVowelBlock = "";
                }
            }
        }
        
        // Process any remaining vowel block at the end of the string
        if (!currentVowelBlock.empty()) {
            totalCount += (atMostKDistinct(currentVowelBlock, 5) - atMostKDistinct(currentVowelBlock, 4));
        }

        return totalCount;
    }
};

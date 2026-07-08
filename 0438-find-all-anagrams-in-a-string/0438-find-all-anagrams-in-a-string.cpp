class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[])
{ // it wil check wether the two freq are equal or not
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}
vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int freq[26] = {0};
    for (int i = 0; i < p.length(); i++)
    {
        freq[p[i] - 'a']++;
    }
    int windsize = p.length();
    for (int left = 0; left < s.length(); left++)
    {
        int windFreq[26] = {0};
        int right = left, windIND = 0;
        while (windIND < windsize && right < s.length())
        { // sliding window
            windFreq[s[right] - 'a']++;
            windIND++;
            right++;
        }
        if (isFreqSame(windFreq, freq))
        {
            ans.push_back(left);
        }
    }
    return ans;
}
};
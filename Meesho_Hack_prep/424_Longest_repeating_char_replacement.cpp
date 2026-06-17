


class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0, ans = 0, maxFreq = 0;

        vector<int> freq(26, 0);

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i]-'A']);

            while (i-j + 1 - maxFreq > k) {freq[s[j]-'A']--; j++;}
            ans = max(ans, i-j+1);
        }

        return ans;
    }
};
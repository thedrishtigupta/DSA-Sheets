
//Sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        unordered_map<char, int> m;
        int j = 0;

        for(int i = 0; i < n; i++) {
            m[s[i]]++;
            
            while(m[s[i]] > 1) {
                m[s[j]]--;
                j++;
            }

            maxLen = max(maxLen, i-j+1);
        }
        return maxLen;
    }
};


// Last index where char was seen
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0, maxLen = 0;

        unordered_map<char, int> m;
        int j = 0;

        for(int i = 0; i < n; i++) {
            if (m.count(s[i]) && m[s[i]] >= j) j = m[s[i]] + 1;
            else len = i - j + 1;

            maxLen = max(maxLen, len);
            m[s[i]] = i;
        }
        return maxLen;
    }
};
*/

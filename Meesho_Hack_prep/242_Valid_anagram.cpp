
// Use freq vector

class Solution {
public:
    bool isAnagram(string a, string b) {
        if (a.length() != b.length()) return false;
        vector<int> count(26, 0);

        for(char ch: a) count[ch-'a']++;

        for(char ch: b) count[ch-'a']--;

        for(int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;

        
    }
};
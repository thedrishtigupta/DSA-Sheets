

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        unordered_set<int> s;

        for(int val : nums) s.insert(val);

        int ans = 1;

        for(auto& it : s) {
            if(!s.count(it-1)) {
                int x = it, cnt = 1;
                while(s.count(x+1)) {x++; cnt++;}
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
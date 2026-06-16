
// Use set to find sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        unordered_set<int> s;

        for(int val : nums) s.insert(val);

        int ans = 1;

        for(auto val : s){
            if (!s.count(val-1)) {
                int x = val, cnt = 1;
                while(s.count(x+1)) {cnt++; x++;}
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
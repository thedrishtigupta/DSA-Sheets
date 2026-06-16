

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int b = target - nums[i];

            if(m.count(b)) return {i, m[b]};
            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};
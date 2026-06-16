

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Sum, freq

        int sum = 0, ans = 0;

        for(int val : nums) {
            sum += val;

            if(sum == k) ans++;

            int rem = sum - k;

            if (mp.count(rem)) ans += mp[rem];

            if(!mp.count(sum)) mp[sum] = 0;
            mp[sum]++;
        }

        return ans;
    }
};
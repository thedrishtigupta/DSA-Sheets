
// Sliding window

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = prices[0];

        for(int val : prices) {
            if (val > buy) ans = max(ans, val - buy);
            buy = min(buy, val);
        }
        return ans;
    }
};
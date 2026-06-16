
// Use minHeap for freq.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int val : nums) mp[val]++;

        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> minHeap;

        for(const auto& [val, freq] : mp) {
            if (minHeap.size() < k) minHeap.push({freq, val});
            else {
                pair<int, int> top = minHeap.top();
                if (top.first < freq) {
                    minHeap.pop();
                    minHeap.push({freq, val});
                }
            }
        }

        vector<int> ans;

        while(!minHeap.empty()){
            pair<int, int> top = minHeap.top(); minHeap.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
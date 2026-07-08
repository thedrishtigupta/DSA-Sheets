

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_map<int, int> mp;

        for(int val : nums) mp[val]++;

        vector<int> ans;

        for(auto& [val, freq] : mp) {
            if(pq.size() < k) pq.push({freq, val});
            else {
                pair<int, int> top = pq.top();

                if(top.first < freq) {
                    pq.pop();
                    pq.push({freq, val});
                }
            }
        }

        while(!pq.empty()) {
            pair<int, int> top = pq.top(); pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};
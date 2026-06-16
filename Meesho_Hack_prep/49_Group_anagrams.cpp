
/*
key     |   [strs]
aet     |   [eat, ate, tea]
ant     |   [tan, ant]
abt     |   [bat]

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto& str: strs) {
            string key = str;
            sort(begin(key), end(key));
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(const auto& [_, group]: mp) ans.push_back(group);
        return ans;
    }
};
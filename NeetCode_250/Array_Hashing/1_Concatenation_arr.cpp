
/*
LC 1929 : Concatenation of array

Create new array ans of double length as nums, loop thorugh and concatenate using indexing.
*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2*n, 0);

    for(int i = 0; i < n; i++) {
        ans[i] = nums[i];
        ans[i+n] = nums[i];
    }
    return ans;
}

int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    vector<int> ans = getConcatenation(nums);

    for(int val : ans) cout<<val<<" ";
    return 0;
}

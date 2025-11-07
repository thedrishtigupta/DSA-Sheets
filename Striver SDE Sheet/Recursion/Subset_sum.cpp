
/*
Find all subsets whose sum equal target.
Here we use the inclusion-exclusion principle.
For every element we have a choice whether to include it in calculation or not.
We check if the sum yet is equal to target, if yes, add it to answer, or else keep recursing.
*/

#include <iostream>
#include<vector>
using namespace std;

void subsetSum(vector<int>& arr, int tar, vector<vector<int>>& ans, vector<int>&op, int i = 0, int sum = 0) {
    if(sum == tar) {
        ans.push_back(op);
        return;
    }
    if(i >= arr.size() || sum > tar) return;

    //include
    op.push_back(arr[i]);
    sum += arr[i];
    subsetSum(arr, tar, ans, op, i+1, sum);

    // exclude
    op.pop_back();
    sum -= arr[i];
    subsetSum(arr, tar, ans, op, i+1, sum);
}
int main() {
    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    int tar; cin>>tar;

    vector<vector<int>> ans;
    vector<int> op;

    subsetSum(arr, tar, ans, op);

    for(int i = 0; i < ans.size(); i++) {
        for(int val : ans[i]) cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}
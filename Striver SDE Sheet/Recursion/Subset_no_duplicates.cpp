
/*
On observation, we see that duplicates occurs, when we first exclude and then include the same value.
therefore, we need to skip the include part for same values, and for that we use a loop which check for same values.
But first, we need to sort the whole array.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAll(vector<int> arr, int n,  vector<vector<int>>& ans, vector<int>& op, int i = 0) {
    if (i >= n) {ans.push_back(op); return;}

    // include
    op.push_back(arr[i]);
    getAll(arr, n, ans, op, i+1);

    //backtrack
    op.pop_back();

    //skip same elements
    int j = i+1;
    while(j < n && arr[j] == arr[j-1]) j++;

    //exclude
    getAll(arr, n, ans, op, j); // j because even if no duplicate elements present, it already is i+1
}
int main() {
    int n; cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    vector<int> op;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());
    getAll(arr, n, ans, op);

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        for(int val : ans[i]) cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}
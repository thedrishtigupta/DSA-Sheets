
/*
LeetCode: 118

We are given a number n, and we have to build pascal's triangle using it.
Suppose n = 6;
0|   1
1|   1   1
2|   1   2   1
3|   1   3   3   1
4|   1   4   6   4    1
5|   1   5   10  10   5  1

Here, no. of col = no. of row + 1
and relation for building pascal is:
    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

As for j = 0 and last, values are 1, we use it for initialization
*/

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascal(int n) {
    vector<vector<int>> ans(n);

    for(int i = 0; i < n; i++) {
        vector<int> row(i+1, 1);
        for(int j = 1; j < i; j++) { // loop not run for 0th and last col
            row[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans[i] = row;
    }
    return ans;
}
int main() {
    int n; cin>> n;

    vector<vector<int>> pas = pascal(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) cout<<pas[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
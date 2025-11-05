
/*
We have to rotate matrix to 90 degrees clockwise.

    1   2   3       7   4   1
    4   5   6   ->  8   5   2
    7   8   9       9   6   3

to do this:
    1. transpose of matrix
        1   2   3       1   4   7
        4   5   6   ->  2   5   8
        7   8   9       3   6   9
    2. reverse row wise
        1   4   7       7   4   1
        2   5   8   ->  8   5   2
        3   6   9       9   6   3
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();

    // 1. transpose
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) { //i+1, to ensure no double swapping
            swap(mat[i][j], mat[j][i]);
        }
    }


    // 2. row reverse
    for(int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}
int main() {
    int n; cin>>n;

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin>>mat[i][j];
    }

    rotate(mat);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    return 0;
}
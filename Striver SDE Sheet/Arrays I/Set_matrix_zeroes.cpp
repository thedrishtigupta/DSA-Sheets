
/*
LeetCode : 73
-> In place changes

Idea: Optimal approach is to use constant space,
we do this by keeping track of rows and columns to turn 0,
by using 0th row and col for same, instead of making new row and col vector.
Use an extra variable col0 to store col0 value as (0,0) can only be used once.
And we use (0,0) for storing row.

We store, then check and change for (1, 1) to (n-1, m-1).

And lastly, we check and change for (0, 0) and col0. for first row and first col.
*/

#include <iostream>
#include<vector>
using namespace std;

void setMatrixZero(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    int col0 = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                mat[i][0] = 0; // row storage
                if(j != 0) mat[0][j] = 0; // col storage
                else col0 = 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(mat[i][j] != 0) { // no need to change if already 0
                if((mat[i][0] == 0) || (mat[0][j] == 0)) mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0) {
        for(int j = 0; j <m; j++) {
            mat[0][j] = 0;
        }
    }

    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
}

int main() {
    int n; cin>>n;
    int m; cin>>m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {cin>>mat[i][j];}
    }

    setMatrixZero(mat);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {cout<<mat[i][j]<<" ";}
        cout<<endl;
    }
    return 0;
}
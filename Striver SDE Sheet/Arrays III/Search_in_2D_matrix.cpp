
/*
Return true/ false for element to search.

WE use double binary search here, for t.c. to be O(log(m*n)).
First for choosing row, then to searching in that row.
*/

#include <iostream>
#include<vector>
using namespace std;

bool searchRow(vector<vector<int>>& arr, int row, int tar) {
    int n = arr[0].size();
    int i = 0, j = n-1;

    while(i <= j) {
        int m = i + ((j-i)/2);
        if(arr[row][m] == tar) return true;
        else if(arr[row][m] > tar) j = m-1;
        else i = m+1;
    }
    return true;
}
bool searchMatrix(vector<vector<int>>& arr, int tar) {
    int n = arr.size(), m = arr[0].size();
    int startRow = 0, endRow = n-1;

    while(startRow <= endRow) {
        int midRow = startRow + ((endRow - startRow)/2);

        if((arr[midRow][0] <= tar) && (arr[midRow][m-1] >= tar)) return searchRow(arr, midRow, tar);
        else if (arr[midRow][0] >= tar) endRow = midRow-1;
        else startRow = midRow + 1;
    }

    return false;
}
int main() {
    int n, m; cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin>>arr[i][j];
    }

    int tar; cin>>tar;

    if(searchMatrix(arr, tar)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
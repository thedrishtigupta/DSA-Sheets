
/*
Inversions in arrays are define by two conditions -
    1. i < j
    2. arr[i] > arr[j]
If any pair of elements in array satisfies it, its an inversion.

We use merge sort algo for this, as for inversions, all we need to do is find elements greater of left side.
When we merge, we are checking just that, through comparisons.
*/

#include <iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int s, int m, int e) {

    int i = s, j = m+1;
    vector<int> temp;
    int count = 0;

    while(i <= m && j <= e) {
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            count += (m - i + 1);
        }
    }

    while(i <= m) temp.push_back(arr[i++]);
    while (j <= e) temp.push_back(arr[j++]);

    int size = temp.size();
    for(int k = 0; k < size; k++) arr[k+s] = temp[k];

    return count;
}
int mergeSort(vector<int>& arr, int s, int e) {
    if(s >= e) return 0;

    int m = s + ((e-s)/2);

    int left = mergeSort(arr, s, m);
    int right = mergeSort(arr, m+1, e);

    int inv = merge(arr, s, m, e);

    return left + right + inv;
}
int main() {
    int n; cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    cout<<mergeSort(arr, 0, n-1);
    return 0;
}
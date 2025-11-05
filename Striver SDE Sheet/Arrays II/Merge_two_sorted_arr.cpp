
/*
We are already given space in the first array, we just need to add the elements from second array to it,
such that the array remains sorted.

We do this by taking 3 points, we traverse from back since its sorted we dont need to check for every element.
We take pointer i to the end of elements in array 1 and j to end of array 2 and k to extra space end
We check for i and j first, and then place it.
*/

#include <iostream>
#include<vector>
using namespace std;

void mergeSorted(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n-1, j = m-1, k = n+m-1;

    while(i >= 0 && j >= 0) {
        if(a[i] >= b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }

    //for remaining, if any
    while(j >= 0) a[k--] = b[j--];
}

int main() {
    int n, m; cin>>n>>m;

    vector<int> a(n+m), b(m);

    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    mergeSorted(a, n, b, m);
    for(int i = 0; i < n+m; i++) cout<<a[i]<<" ";
    return 0;
}
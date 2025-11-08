
/*
The idea is that all pairs start from even index until a single element is encountered.
So if m is even and m+1 are same elements, that means the pattern is not broken yet,
and no single element is there on left side.
And similarly, if m is odd and m-1 are same elements, then also pattern not broken.
Therefore we search in RHS.
But if its not the case then there is a break in pattern and unique lies in LHS.
*/



#include <iostream>
#include<vector>
using namespace std;

int primal(vector<int>& arr) {
    int s = 0, e = arr.size()-1;

    while(s <= e) {
        int m = s + ((e-s)/2);
        if(arr[m] != arr[m-1] && arr[m] != arr[m+1]) return arr[m];
        else if(arr[m] == arr[m+1]) {
            if((e-m+1) % 2 == 0) e = m-1;
            else s = m+1;
        } else if(arr[m] == arr[m-1]) {
            if((m-s+1) % 2 == 0) s = m+1;
            else e = m-1;
        }
    }
    return -1;
}

int optimal(vector<int>& arr) {
    int s = 0, e = arr.size()-1;

    while(s < e) {
        int m = s + ((e-s)/2);

        if((m % 2 == 0 && arr[m] == arr[m+1]) ||(m % 2 == 1 && arr[m] == arr[m-1]))
            s = m+1;
        else e = m-1;
    }
    return arr[s];
}
int main() {
    int n; cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    cout<<"Unique: "<<optimal(arr)<<endl;
    return 0;
}
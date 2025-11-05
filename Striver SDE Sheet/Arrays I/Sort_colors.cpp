
/*
We are supposed to sort 0s, 1s and 2s in array. it could have been colors also.
Here we use intervals, to sort them.
Since there are 3 types to be sorted, we need 3 variables.
    - Range(0, a-1) -> store 0s.
    - Range(a, b-1) -> store 1s.
    - Range(b, c) -> contains unsorted elements.
    - Range(c+1, n-1) -> store 2s.

    Initially, a = b = 0, and c = n-1.
*/

#include <iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums){
    int n = nums.size();

    int a = 0, b = 0, c = n-1;

    while(b <= c) { //contains unsorted elements
        if(nums[b] == 0) swap(nums[a++], nums[b++]);
        else if(nums[b] == 1) b++;
        else swap(nums[c--], nums[b]);
    }
}
int main() {
    int n; cin>>n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    sortColors(nums);
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    return 0;
}
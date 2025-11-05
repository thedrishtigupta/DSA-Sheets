
/*
Next permutation of 123654 -> 124356

Steps:
    1. Find pivot index: pivot is the rightmost element which is smaller than its next (here 3)
    2. Swap pivot element with rightmost element greater than pivot (here, 4 -> 124653)
    3. Reverse array from pivot+1 to end (124356)
If its already decreasing, just reverse the entire array
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void next_permutation(vector<int>& nums) {
    int n = nums.size();

    int pivot = -1;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {pivot = i; break;}
    }

    if(pivot == -1) {reverse(nums.begin(), nums.end()); return;}

    for(int i = n-1; i > pivot; i--) {
        if(nums[i] > nums[pivot]) {swap(nums[i], nums[pivot]); break;}
    }

    reverse(nums.begin()+pivot+1, nums.end());
}
int main() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    next_permutation(nums);
    for(int i = 0; i < n; i++) cout<<nums[i]<<" ";
    return 0;
}
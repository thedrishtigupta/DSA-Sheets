
/*
We observed a pattern that no matter what n is, the number of elements with freq > n/3 will always be 1 or 2.

1.  arr = [3], n = 1. -> freq of 3 = 1, n /3 = 0, freq of 3 > 0.
    ans = [3]
2.  arr = [3, 2], n = 2. n/3 = 0. freq 1 > 0.
    ans = [3,2]
3.  arr = [3,2,3], n = 3. n/3 = 1. freq > 1.
    ans = [3] ->freq of 3 is 2.
4.  arr = [3,2,3,2], n = 3. n/ 3 = 1. freq > 1.
    ans = [3,2] -> both have freq = 2
5.  arr = [3, 2, 4, 3, 2, 3], n = 6. n/3 = 2. freq > 2.
    ans = [3] ->freq = 3

So we need only find 2 elements whose freq will be greater than n/3.
then we recheck if their frequency really is greater, if yes, we push them in answer.
*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> major3(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    int el1, el2, f1 = 0, f2 = 0;

    // find el1 and el2
    for(int val : nums) {
        if(val == el1) f1++;
        else if(val == el2) f2++;
        else if(f1 == 0) {el1 = val; f1++;}
        else if(f2 == 0) {el2 = val; f2++;}
        else {f1--; f2--;}
    }

    // check for actual frequency
    f1 = 0, f2 = 0;
    for(int val : nums) {
        if(val == el1) f1++;
        else if(val == el2) f2++;
    }

    // see if it matches the condition
    if(f1 > n/3) ans.push_back(el1);
    if(f2 > n/3) ans.push_back(el2);

    return ans;
}
int main() {
    int n; cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    vector<int> ans = major3(nums);
    for(int val : ans) cout<<val<<" ";
    cout<<endl;
    return 0;
}
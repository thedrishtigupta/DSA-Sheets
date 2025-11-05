
/*
Find maximum subarray sum

Here we use kadane's algo which says that whenever your sum becomes less than 0, re-initialize it to 0.

Basically, we check if we want to keep the previous value, or start new sum taking.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxKadane(vector<int>& nums) {
    int n = nums.size();
    int sum = 0, int maxSum = nums[0];

    for(int val : nums){
        sum = max(val, sum+val);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main() {
    int n; cin>>n;
    vector<int>nums(n);

    for(int i = 0; i < n; i++) cin>>nums[i];

    cout<<maxKadane(nums)<<endl;
    return 0;
}
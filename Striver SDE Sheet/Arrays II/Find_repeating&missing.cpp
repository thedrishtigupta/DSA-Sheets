
/*
To find repeating value, we can either use unordered_set or slow-fast pointer method.
Lets call repeating value a.
Since elements lie in range [1, N], we can calculate their sum from 1toN (expected) and the actual sum.
Missing value -> b = (expectedSum - actualSum) + a
*/

#include <iostream>
#include<vector>
using namespace std;

pair<int, int> miss_repeat(vector<int>& nums) {
    int n = nums.size();
    int slow = nums[0], fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    slow = nums[0];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    int a = slow;

    int expectedSum = n*(n+1)/2;
    int sum = 0;

    for(int val : nums) sum += val;

    int b = (expectedSum - sum) + a;

    return {a, b};
}
int main() {
    int n; cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    pair<int, int> p = miss_repeat(nums);
    cout<<"["<<p.first<<","<<p.second<<")"<<endl;
    return 0;
}
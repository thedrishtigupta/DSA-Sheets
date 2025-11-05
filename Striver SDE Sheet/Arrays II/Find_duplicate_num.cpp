
/*
We are given an array, which contains 1 to n digits, and size of array is n+1, which means it contains a duplicate value.
We can use unordered_set to easily find out.

But, we are going to use Linked List cycle detection method here, using slow-fast pointer.

if our array :
arr=    1   3   4   2   2 <- next node
idx=    0   1   2   3   4 <- node

We form a linked list, and since it contains duplicate it will always contain a cycle.
0 -> 1-> 3 -> 2 -> 4 -> 2 (cycle)

Same logic as in Linked List cycle detection.
*/

#include <iostream>
#include<vector>
using namespace std;

int duplicate(vector<int>& nums) {
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
    return slow;
}
int main() {
    int n; cin>>n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    cout<<duplicate(nums)<<endl;
    return 0;
}

/*
NOTE: If it only contains duplicate element twice, can solve it using sum also.
*/
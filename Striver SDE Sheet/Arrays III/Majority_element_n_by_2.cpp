
/*
In this, we use Moore's voting algorithm.
Which says, no matter how many contestants participate in a voting, the one with the most votes wins.
So in same way, all we need to do is count the element with maximum frequency and store it in answer.
*/

#include <iostream>
#include <vector>
using namespace std;

int major(vector<int>& nums) {
    int freq = 0, ans = nums[0];

    for(int val : nums) {
        if(freq == 0) ans = val;
        freq += val == ans ? 1 : -1;
    }
    return ans;
}
int main() {
    int n; cin>>n;

    vector<int>nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];

    cout<<major(nums)<<endl;
    return 0;
}
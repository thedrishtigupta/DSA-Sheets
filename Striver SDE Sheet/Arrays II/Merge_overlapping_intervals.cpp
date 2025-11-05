
/*
We say that two intervals are overlapping when the start of next interval is before the end of prev interval.

for ex. :
    (1, 3)
    (2, 6)
    (8, 10)
    (15, 18)

Here, (1, 3) and (2, 6) are overlapping and can be merged as -> (1, 6).

But in order to do this, we must have the intervals sorted, based on their starting time.

So :
step 1. Sort the intervals, row wise
step 2. compare the end of prev with start of curr, if mergeable update, else push back in ans
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



vector<pair<int, int>> merge(vector<pair<int, int>> interval) {
    int n = interval.size();

    if(n < 1) return {};
    vector<pair<int, int>> ans;
    pair<int, int> prev;

    sort(interval.begin(), interval.end());

    prev = interval[0];

    for(int i = 1; i < n; i++) {
        if(interval[i].first > prev.second) {
            ans.push_back(prev);
            prev = interval[i];
        } else {
            prev.second = max(prev.second, interval[i].second);
        }
    }
    ans.push_back(prev);
    return ans;

}
int main() {
    int n; cin>>n;
    
    vector<pair<int, int>> interval(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        interval[i] = {a, b};
    }

    vector<pair<int, int>> merged = merge(interval);

    for(auto &p : merged) {
        cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
    }
    return 0;
}
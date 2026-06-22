#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long m, vector<long long>& arr, long long t) {
    long long prod = 0;

    for(long long val : arr) {
        prod += m / val;

        if(prod >= t) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;
    cin >> n >> t;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    long long l = 1, r = 1e18;

    while(l <= r) {
        long long mid = l + (r - l) / 2;

        if(isPossible(mid, arr, t)) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << endl;
}
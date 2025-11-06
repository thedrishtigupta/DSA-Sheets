
/*
Here, we use binary exponentiation. (a maths concept) -> O(log n)

Suppose we have to find pow(3, 5).
If we were to do it through multiplication or inbuilt function, it might give TLE.
Since -2^31 <= n <= 2^31 -1. the T.C. will be O(n) >> 10^8 -> TLE

We take x = 3, n = 5.
So instead of looping of n, we loop on binary form of n (5 -> 101).
Note: No. of digits in n = log(n) base 2 + 1
We only take 1 bit digits
    x^4 x^2 x^1
    1   0   1
    3^4 3^2 3^1
We only multiply 1 bit digits to our final answer so 3^4 * 3^1 = 3^5.
And everytime, we just square the x.
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if(n == 0 || x == 1) return 1;
    if(x == 0) return 0;
    if(n < 0) {x = 1/x; n = -n;}

    int ans = 1;

    while(n > 0) {
        if(n % 2 == 1) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}
int main() {
    double x; cin>>x;
    int n; cin>>n;

    cout<<myPow(x, n)<<endl;
    return 0;
}
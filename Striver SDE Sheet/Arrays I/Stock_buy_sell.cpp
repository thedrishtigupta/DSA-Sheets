
/*
We need to find maximum profit.
When to buy stock? - on lowest price.
When to sell stock? - on highest price.

Instead of finding the best selling price, we find the best buying price and then calculate the max profit using that.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int lowest = prices[0], profit = 0;

    for(int price: prices) {
        if(price > lowest) profit = max(profit, price - lowest);
        lowest = min(lowest, price);
    }
    return profit;
}

int main() {
    int n; cin>>n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin>>prices[i];

    cout<<maxProfit(prices)<<endl;
    return 0;
}
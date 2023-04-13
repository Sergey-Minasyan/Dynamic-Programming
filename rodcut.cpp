#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cutRod(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int maxVal = INT_MIN;
        for (int j = 0; j < i; j++) {
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(int w, const std::vector<int>& weights, const std::vector<int> v, int n)
{
    int T[n + 1][w + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            if (i == 0 || j == 0)
                T[i][j] = 0;
            else if (j >= weights[i - 1])
                T[i][j] = std::max(v[i - 1] + T[i - 1][j - weights[i - 1]], T[i - 1][w]);
            else
                T[i][j] = T[i - 1][j];
        }
    }
    return T[n][w];
}
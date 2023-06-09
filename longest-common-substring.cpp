#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int lca_length(const std::string& a, const std::string& b)
{
    int m = a.length();
    int n = b.length();
    std::vector<std::vector<int>> c;
    for (int i = 0; i < m; ++i)
        c[i][0] = 0;
    for (int j = 0; j < n; ++j)
        c[0][j] = 0;
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (a[i] == b[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    return c[m][n];
}
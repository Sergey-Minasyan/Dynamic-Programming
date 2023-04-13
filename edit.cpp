#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int min(int x, int y, int z) {
    return std::min(std::min(x, y), z);
}


int edit(const std::string& s1, const std::string& s2)
{
    int n = s1.length();
    int m = s2.length();
    int T[n + 1][m + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (s1[i] == s2[j])
                T[i][j] = T[i - 1][j - 1];
            else
                T[i][j] = min(T[i - 1][j - 1], T[i - 1][j], T[i][j - 1]) + 1;
        }
    }
    return T[n][m];
}
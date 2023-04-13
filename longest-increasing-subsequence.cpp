#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int>& nums) {
    vector<int> piles;
    for (int num : nums) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        if (it == piles.end()) {
            piles.push_back(num);
        }
        else {
            *it = num;
        }
    }
    return piles.size();
}

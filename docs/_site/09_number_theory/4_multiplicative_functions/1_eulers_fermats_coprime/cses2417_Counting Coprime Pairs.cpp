#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxValue = 1e6 + 10;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; cin >> n;
    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    std::vector<int> seives(maxValue);
    std::vector<vector<int>> divisorsOf(maxValue);
    for (int i = 2; i < maxValue; i++) {
        if (divisorsOf[i].size() == 0) {
            for (int j = i; j < maxValue; j += i) {
                divisorsOf[j].push_back(i);
            }
        }
    }
    std::vector<int> valueDivisibleBy(maxValue);
    std::vector<int> primeDivisorsOf(maxValue);
    for (int i = 0; i < n; i++) {
        for (int mask = 1; mask < (1 << (divisorsOf[values[i]].size())); mask++) {
            int combination = 1;
            int primeDivisor = 0;
            for (int pos = 0; pos < divisorsOf[values[i]].size(); pos++) {
                if ((1 << pos)&mask) {
                    combination *= divisorsOf[values[i]][pos];
                    primeDivisor++;
                }
            }
            primeDivisorsOf[combination] = primeDivisor;
            valueDivisibleBy[combination]++;
        }
    }
    int totalNumberOfPairs = (n * (n - 1)) / 2;
    int validPairs = 0;
    for (int i = 0; i < maxValue; i++) {
        if (primeDivisorsOf[i] & 1) {
            validPairs += (valueDivisibleBy[i] * (valueDivisibleBy[i] - 1)) / 2;
        } else {
            validPairs -= (valueDivisibleBy[i] * (valueDivisibleBy[i] - 1)) / 2;

        }
    }
    cout << totalNumberOfPairs-validPairs<< endl;
    return 0;
}
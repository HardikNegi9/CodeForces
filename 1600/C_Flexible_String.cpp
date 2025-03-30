#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;

        vector<char> unique_vec;
        bool seen[26] = {0};
        for (char c : a) {
            if (!seen[c - 'a']) {
                seen[c - 'a'] = true;
                unique_vec.push_back(c);
            }
        }

        long long result = 0;

        int subset_limit = min(k, (int)unique_vec.size());
        
        for (int mask = 0; mask < (1 << unique_vec.size()); mask++) {
            int subset_size = __builtin_popcount(mask);
            if (subset_size != subset_limit) continue;
            
            bool s_chars[26] = {0};
            for (int i = 0; i < unique_vec.size(); i++) {
                if (mask & (1 << i)) {
                    s_chars[unique_vec[i] - 'a'] = true;
                }
            }

            long long count = 0, res = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i] || s_chars[a[i] - 'a']) {
                    count++;
                } else {
                    res += count * (count + 1) / 2;
                    count = 0;
                }
            }
            res += count * (count + 1) / 2;
            result = max(result, res);
        }

        cout << result << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        int maxPos = pos.empty() ? INT_MIN : *max_element(pos.begin(), pos.end());
        int minNeg = neg.empty() ? INT_MAX : *min_element(neg.begin(), neg.end());
        long long constant = maxPos - minNeg;

        if (constant <= 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            sort(pos.rbegin(), pos.rend());
            sort(neg.rbegin(), neg.rend());

            vector<int> res;
            long long sum = 0;

            for (int i = 0; i < (int)pos.size(); i++) {
                while (!neg.empty() && sum + pos[i] >= constant) {
                    sum += neg.back();
                    res.push_back(neg.back());
                    neg.pop_back();
                }
                sum += pos[i];
                res.push_back(pos[i]);
            }

            for (auto &x : neg) {
                res.push_back(x);
            }

            for (auto &x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
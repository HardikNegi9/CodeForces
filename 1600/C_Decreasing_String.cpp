#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

void solve() {
    string s;
    cin >> s;

    long long pos;
    cin >> pos;

    stack<long long> stk;
    vector<long long> v;

    // Generate the lexicographically minimal sequence
    for (long long i = 0; i < s.size(); i++) {
        while (!stk.empty() && s[stk.top()] > s[i]) {
            v.push_back(stk.top());
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty()) {
        v.push_back(stk.top());
        stk.pop();
    }

    long long n = s.size();
    set<long long> st;
    long long p = 0;

    // Determine the string and position
    while (pos > n) {
        pos -= n;
        n--;
        st.insert(v[p++]);
    }

    // Find the character at position pos
    for (long long i = 0; i < s.size(); i++) {
        if (st.count(i)) continue;
        pos--;
        if (pos == 0) {
            cout << s[i];
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
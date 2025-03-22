#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool cycle;

void dfs(int curr, vector<bool> &visited, set<int> adj[]) {
    visited[curr] = true;
    int visCount = 0;

    for (auto el : adj[curr]) {
        if (visited[el]) {
            visCount++;
            continue;
        }
        dfs(el, visited, adj);
    }

    if (visCount > 1) {
        cycle = true;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    set<int> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        adj[i].insert(arr[i]);
        adj[arr[i]].insert(i);
    }

    vector<bool> visited(n + 1, false);

    int cc = 0;          // Connected components count
    int cycleCount = 0;  // Cycle count

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cc++;
            cycle = false;
            dfs(i, visited, adj);
            if (cycle) {
                cycleCount++;
            }
        }
    }

    cout << cycleCount + (cc != cycleCount) << " ";
    cout << cc << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
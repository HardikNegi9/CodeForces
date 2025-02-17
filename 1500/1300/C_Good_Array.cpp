#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<long long, vector<int>> numIndices;
    long long total = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        numIndices[a[i]].push_back(i);
    }
    
    vector<int> nice;
    for(int i = 0; i < n; i++) {
        long long remaining = total - a[i];
        if(remaining % 2 == 0) {
            long long target = remaining/2;
            auto it = numIndices.find(target);
            if(it != numIndices.end()) {
                for(int idx : it->second) {
                    if(idx != i) {
                        nice.push_back(i + 1);
                        break;
                    }
                }
            }
        }
    }
    
    cout << nice.size() << endl;
    for(int idx : nice) cout << idx << " ";
    return 0;
}
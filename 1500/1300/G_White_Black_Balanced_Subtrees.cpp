#include<iostream>
#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        a[0] = -1;
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;

        long long res = 0;

        unordered_map<int, vector<int>> adj;

        for(int i = 1; i < n; i++){
            adj[a[i]].push_back(i + 1);
        }


        function<pair<int, int>(int)> solve = [&](int node) -> pair<int, int>{
            if(adj[node].size() == 0){
                pair<int, int> p = {0, 0};
                s[node - 1] == 'W' ? p.first++ : p.second++;
                return p;
            }

            pair<int, int> curr = {0, 0};
            for(int neb : adj[node]){
                pair<int, int> p = solve(neb);
                curr.first += p.first;
                curr.second += p.second;
            }

            s[node - 1] == 'W' ? curr.first++ : curr.second++;

            if(curr.first == curr.second){
                res++;
            }

            return curr; 
        };

        solve(1);
        cout << res << endl;
    }
}
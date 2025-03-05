#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000007;

long long power(long long n, int k){
    long long res = 1;
    while(k > 0){
        if(k % 2 == 1){
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}
class DisJoint{
    vector<int> parent, size;
    int n;

    public:
        DisJoint(int n){
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);

        if(x != y){
            if(size[x] < size[y]){
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }
    }

    long long cal_path(int k){
        long long sum = 0;

        for(int i = 1; i <= n; i++){
            if(parent[i] == i){
                long long x = size[i];
                (sum += power(x, k)) %= MOD;
            }
        }

        return sum;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);

    for(int i = 1; i < n; i++){
        int u, v, x;
        cin >> u >> v >> x;

        if(x == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    long long sum = power(n, k);

    DisJoint ds(n);
    for(int i = 1; i <= n; i++){
        for(int v : adj[i]){
            ds.merge(i, v);
        }
    }

    long long ans = ds.cal_path(k);
    cout << (sum - ans + MOD) % MOD << endl;
}
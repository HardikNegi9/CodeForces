#include<iostream>
#include<vector>

using namespace std;

class DisJoint{
    vector<int> parent;
    vector<int> size;

public:
        DisJoint(int n){
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void join(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int get(int a){
        return size[find(a)];
    }
};



int main(){
    int n, m;
    cin >> n >> m;

    DisJoint ob(n);

    while(m--){
        int k; cin >> k;
        if(k == 0) continue;
        int a; cin >> a;
        int b;
        for(int i = 1; i < k; i++){
            cin >> b;
            ob.join(a, b);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ob.get(i) << " ";
    }


}
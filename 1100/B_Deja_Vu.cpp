#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> a(n), x(q);
        vector<bool> done(n, false);
        vector<vector<int>> pow(31);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < q; i++){
            cin >> x[i];
        }


        for(int i = 30; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(done[j]) continue;
                if(a[j] % (1 << i) == 0){
                    done[j] = 1;
                    pow[i].push_back(j);
                }
            }
        }


        for(int i : x){
            for(int j = i; j <= 30; j++){
                for(int idx : pow[j]){
                    pow[i - 1].push_back(idx);
                    a[idx] += (1 << (i - 1));
                }
                pow[j].clear(); 
            }
        }

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;   
    }
}
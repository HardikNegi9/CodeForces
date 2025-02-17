#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int i = 0, j = 0;
    int res = 0;

    vector<bool> pos(n + 1, false);

    while(i < n && j < n){
        if(pos[a[i]]){
            i++;
            continue;
        }
        if(a[i] == b[j]){
            i++;
            j++;
        }
        else{
            pos[b[j]] = true;
            res++;
            j++;

        }
    }

    cout << res << endl;
}
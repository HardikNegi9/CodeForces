#include<iostream>
#include<vector>
#include<map>
using namespace std;


long long __gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return __gcd(b, a % b);
}



int main(){
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    map<pair<long long, long long>, int> map;
    int res = 0;
    int zero = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0 && b[i] != 0) continue;
        if(a[i] == 0 && b[i] == 0){
            zero++;
            continue;
        }
        long long gcd = __gcd(a[i], b[i]);
        pair<long long, long long> val = {a[i] / gcd, b[i] / gcd};
        map[val]++;
        res = max(map[val], res);
    }

    cout << res + zero << endl;
}
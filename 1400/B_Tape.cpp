#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long n, len, k;
    cin >> n >> len >> k;

    vector<long long> tape(n, 0);
    for(long long i = 0; i < n; i++){
        cin >> tape[i];
    }

    vector<long long> diff;
    for(long long i = 0; i < n - 1; i++){
        diff.push_back(tape[i + 1] - tape[i] - 1);
    }

    sort(diff.rbegin(), diff.rend());
    long long res = tape[n - 1] - tape[0] + 1;

    for(long long i = 0; i < k - 1; i++){
        res -= diff[i];
    }

    cout << res;
    
    
}
#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long neg = 0;
    long long pos = 0;
    long long res = 0;
    long long curr = 0;

    for(int i = 0; i < n; i++){
        if(curr % 2 == 0) pos++;
        else neg++;

        if(arr[i] < 0) curr++;
        if(curr % 2 == 0) res += pos;
        else res += neg;
    }

    long long total = n * (n + 1) / 2;
    cout << total - res << " " << res << endl;
}

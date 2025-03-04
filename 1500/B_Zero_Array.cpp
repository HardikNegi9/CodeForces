#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    long long sum = 0;
    int mx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }


    if(sum % 2 == 1 || mx > sum / 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}
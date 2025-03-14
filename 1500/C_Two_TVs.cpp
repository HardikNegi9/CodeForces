#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int count = 1;
    int i = 1, j = 0;

    while(i < n){
        if(a[i] <= b[j]){
            count++;
            i++;
        }else{
            count--;
            j++;
        }

        if(count > 2) break;
    }

    cout << (i == n && count <= 2? "YES" : "NO") << endl;
    return 0;
}
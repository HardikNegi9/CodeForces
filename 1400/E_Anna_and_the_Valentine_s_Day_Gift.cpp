#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        vector<int> leading_zeros;
        int size = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];

            int j = a[i].size()-1;
            while(j >= 0 && a[i][j] == '0'){
                j--;
            }
            leading_zeros.push_back(a[i].size()-j-1);
            size += a[i].size();
        }

        sort(leading_zeros.rbegin(), leading_zeros.rend());
        int ans = 0;
        for(int i = 0; i < n; i+=2){
            size -= leading_zeros[i];
        }

        if(size >= m + 1) cout << "Sasha" << endl;
        else cout << "Anna" << endl;
    }
}
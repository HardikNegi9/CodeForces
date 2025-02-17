#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(n);
        for(int i = 0; i < s.size(); i++){
            a[i] = s[i] - '0';
        }

        for(int i = 1; i < n; i++){
            int j = i;
            while(j > 0 && a[j] > a[j - 1] + 1){
                a[j]--;
                swap(a[j], a[j - 1]);
                j--;
            }
        }

        for(int i = 0; i < n; i++){
            cout << a[i];
        }
        cout << endl;
    }
}
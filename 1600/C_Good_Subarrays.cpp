#include<iostream>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        string s;
        cin >> s;
        map<int, int> mp;
        long long res = 0;
        mp[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int x = s[i] - '0' - 1;
            sum += x;
            res += mp[sum];
            mp[sum]++;
        }
        cout << res << endl;
    }
}
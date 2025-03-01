#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<vector<int>> map(k, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++){
            map[i%k][s[i] - 'a']++;
        }

        long long res = 0;
        for(int i = 0; i < k; i++){
            int max_freq = 0;
            long long sum = 0;
            for(int j = 0; j < 26; j++){
                sum += map[i][j] + map[k-i-1][j];
                max_freq = max(max_freq, map[i][j] + map[k-i-1][j]);
            }
            res += sum - max_freq;
        }

        cout << res/2 << endl;
    }
}
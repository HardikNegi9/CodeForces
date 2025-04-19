#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;


    vector<string> substr;
    for(int i = 1; i <= n; i++){
        substr.push_back(s.substr(0, i));
    }

    vector<string> res;
    for(int i = 0; i < substr.size(); i++){
        string t;
        int m = substr[i].size();
        for(int j = 0; j < k; j++){
            t += substr[i][j % m];
        }
        res.push_back(t);
    }

    sort(res.begin(), res.end());
    cout << res[0] << endl;
}

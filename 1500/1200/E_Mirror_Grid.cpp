#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v1){
    int n = v1.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(v1[i][j], v1[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            swap(v1[i][j], v1[i][n-j-1]);
        }
    }
    return v1;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v1(n);
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            for(int j=0; j<n; j++){
                v1[i].push_back(s[j]-'0');
            }
        }

        auto v2 = rotate(v1);
        auto v3 = rotate(v2);
        auto v4 = rotate(v3);

        auto check = [&](int i, int j){
            int count_0 = 0;
            int count_1 = 0;

            if(v1[i][j] == 0) count_0++;
            else count_1++;

            if(v2[i][j] == 0) count_0++;
            else count_1++;

            if(v3[i][j] == 0) count_0++;
            else count_1++;

            if(v4[i][j] == 0) count_0++;
            else count_1++;

            return min(count_0, count_1);
        };

        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res += check(i, j);
            }
        }

        cout << (res >> 2) << endl;
    }
}
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;

        int n;
        cin >> n;
        vector<long long> x1(n);
        for(int i = 0; i < n; i++){
            cin >> x1[i];
        } 

        cin >> n;
        vector<long long> x2(n);
        for(int i = 0; i < n; i++){
            cin >> x2[i];
        }

        cin >> n;
        vector<long long> y1(n);
        for(int i = 0; i < n; i++){
            cin >> y1[i];
        }

        cin >> n;
        vector<long long> y2(n);
        for(int i = 0; i < n; i++){
            cin >> y2[i];
        }
        long long ar1 = abs(x1[x1.size() - 1] - x1[0]) * h;
        long long ar2 = abs(y1[y1.size() - 1] - y1[0]) * w;
        long long ar3 = abs(x2[x2.size() - 1] - x2[0]) * h;
        long long ar4 = abs(y2[y2.size() - 1] - y2[0]) * w;

        cout << max(ar1, max(ar2, max(ar3, ar4))) << endl;
    }
}
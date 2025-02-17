#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c;
        cin >> n >> c;
        vector<long long> vec(n);

        for(int i = 0; i < n; i++){
            cin >> vec[i];
            vec[i]+= i + 1;
        }

        int res = 0;
        long long sum = 0;
        sort(vec.begin(), vec.end());

        for(int i = 0; i < n; i++){
            sum += vec[i];
            if(sum > c) break;
            res++;
        }

        cout << res << endl;

    }
}
#include<iostream>
#include<vector>
using namespace std;


int setbits(long long n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;

    vector<long long> fact = {1};

    for(int i= 2 ; i<= 14; i++){
        fact.push_back(fact.back()*i);
    }

    while(t--){
        long long n;
        cin >> n;
        int res = 1e9;
        for(int i = 0; i < (1 << 14); i++){
            long long sum = 0;
            int count = 0;
            for(int j = 0; j < 14; j++){
                if((1 << j) & i){
                    sum += fact[j];
                    count++;
                }
            }

            if(sum > n) break;
            
            count += setbits(n - sum);
            res = min(res, count);
        }
        cout << res << endl;
    }

}
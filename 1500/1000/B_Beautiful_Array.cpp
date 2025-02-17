#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k, b, s;
        cin >> n >> k >> b >> s;

        if(s < b*k || s - b*k > (n)*(k - 1)){
            cout << -1 << endl;
            continue;
        }
        else{
            if(s / k == b){
                for(int i = 1; i < n; i++) cout << 0 << " ";
                cout << s << endl;
            }
            else{
                while(s / k != b){
                    cout << k - 1 << " ";
                    s -= k - 1;
                    n--;
                }
                if(n > 1) for(int i = 1; i < n; i++) cout << 0 << " ";
                cout << s << endl;
            }
        }

    }
}
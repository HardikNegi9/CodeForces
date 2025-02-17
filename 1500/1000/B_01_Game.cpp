#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int count_0 = count(s.begin(), s.end(), '0');
        int count_1 = count(s.begin(), s.end(), '1');

        if(count_0 == 0 || count_1 == 0){
            cout << "NET" << endl;
        }
        else{
            if(count_0 == count_1){
                if(count_0 & 1) cout << "DA" << endl;
                else cout << "NET" << endl;
            }
            else{
                int mn = min(count_0, count_1);
                if(mn & 1) cout << "DA" << endl;
                else cout << "NET" << endl;
            }
        }
    }
}
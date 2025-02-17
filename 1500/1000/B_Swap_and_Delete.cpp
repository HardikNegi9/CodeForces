#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();

        int count_1 = count(s.begin(), s.end(), '1');
        int count_0 = count(s.begin(), s.end(), '0');
        int i;
        for(i = 0; i < n; i++){
            if(s[i] == '1'){
                if(count_0 > 0){
                    count_0--;
                }
                else{
                    break;
                }
            }
            else{
                if(count_1 > 0){
                    count_1--;
                }
                else{
                    break;
                }
            }
        }
        cout << n - i << endl;
    }
}
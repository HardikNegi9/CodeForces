#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> left(n);
    vector<int> right(n);


    for(int i = 1; i < n; i++){
        left[i] = left[i - 1] + (s[i - 1] == 'v' && s[i] == 'v');
    }

    for(int i = n - 2; i >= 0; i--){
        right[i] = right[i + 1] + (s[i] == 'v' && s[i + 1] == 'v');
    }

    long long res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            res += (long long)left[i] * right[i];
        }
    }

    cout << res << endl;
    
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<functional>

using namespace std;

void f(string s, int n){
    unordered_map<string, bool> mp;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string ss = s.substr(i, j - i + 1);
            mp[ss] = true;
        }
    }


    for(char c = 'a'; c <= 'z'; c++){
        string ss = "";
        ss += c;
        if(mp.find(ss) == mp.end()){
            cout << ss << endl;
            return;
        }
    }


    for(char c = 'a'; c <= 'z'; c++){
        for(char d = 'a'; d <= 'z'; d++){
            string ss = "";
            ss += c;
            ss += d;
            if(mp.find(ss) == mp.end()){
                cout << ss << endl;
                return;
            }
        }
    }

    for(char c = 'a'; c <= 'z'; c++){
        for(char d = 'a'; d <= 'z'; d++){
            for(char e = 'a'; e <= 'z'; e++){
                string ss = "";
                ss += c;
                ss += d;
                ss += e;
                if(mp.find(ss) == mp.end()){
                    cout << ss << endl;
                    return;
                }
            }
        }
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        f(s, n);
    }
}
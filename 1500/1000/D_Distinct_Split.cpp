#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char , int> map;

        for(char c : s){
            map[c]++;
        }

        int size = map.size();
        int res = 0;
        unordered_map<char, int> map2;

        for(char c : s){
            map[c]--;
            map2[c]++;
            if(map[c] == 0){
                size--;
            }
            res = max(res, size + (int)map2.size());
        }

        cout << res << endl;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> freq;
        unordered_map<char, vector<int>> idxs;
        for(int i = 0; i < n; i++){
            freq[s[i]]++;
            idxs[s[i]].push_back(i);
        }

        string temp = "abcdefghijklmnopqrstuvwxyz";

        sort(temp.begin(), temp.end(), [&](char a, char b){
            return freq[a] > freq[b];
        });

        int diff = INT_MAX, pos = 0, cnt_req = 0;

        for(int unique = 1; unique <= 26; unique++){
            if(n % unique) continue;
            int cnt_per = n / unique;

            vector<int> changes(26, 0);

            for(int i = 0; i < unique; i++) changes[temp[i]] = abs(cnt_per - freq[temp[i]]);
            for(int i = unique; i < 26; i++) changes[temp[i]] = cnt_per;

            int curr_diff = accumulate(changes.begin(), changes.end(), 0);

            if(curr_diff < diff){
                diff = curr_diff;
                pos = unique;
                cnt_req = cnt_per;
            }
        }

        if(diff == 0){
            cout << 0 << endl;
            cout << s << endl;
            continue;
        }

        string res = s;
        int i = 0, j = pos - 1;
        int k = 25;

        while(k >= pos){
            if(freq[temp[k]] != 0){
                int idx = idxs[temp[k]].back();
                idxs[temp[k]].pop_back();
                
            }
        }

        
    }
}
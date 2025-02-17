#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int temp = n;
    vector<int> arr(n + 1);
    map<int, int> map; 
    for(int i=1; i <= n; i++){
        cin>>arr[i];
        if(map.find(arr[i]) == map.end()){
            map[arr[i]] = i;
        }
    }

    while(q--){
        int x;
        cin>>x;
        int pos = map[x];
        cout<<pos<<" ";
        map.erase(x);
        for(auto ele : map){
            if(ele.second < pos){
                map[ele.first]++;
            }
        }
        map[x] = 1;
    }
}
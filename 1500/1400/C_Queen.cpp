#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> parent(n + 1, 0);
    vector<int> resp(n + 1, 0);
    vector<int> remove(n + 1, 0);

    for(int i = 1; i <= n; i++){
        cin >> parent[i];
        cin >> resp[i];
        remove[i] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(resp[i] == 0){
            remove[i] = 0;
            if(parent[i] != -1) remove[parent[i]] = 0;
        }
    }


    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(remove[i]){
            flag = false;
            cout << i << " ";
        }
    }

    if(flag){
        cout << -1;
    }
}
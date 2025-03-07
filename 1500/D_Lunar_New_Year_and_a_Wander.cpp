#include<iostream>
#include<vector>
#include<set>
using namespace std;



int main(){
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n + 1, false);
    vector<vector<int>> map(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    set<int> st;
    st.insert(0);
    visited[0] = true;
    while(st.size()){
        int node = *st.begin();
        st.erase(st.begin());
        cout << node + 1 << " ";
        for(int i = 0; i < map[node].size(); i++){
            if(!visited[map[node][i]]){
                visited[map[node][i]] = true;
                st.insert(map[node][i]);
            }
        }
    }
}
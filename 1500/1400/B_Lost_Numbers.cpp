#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {4, 8, 15, 16, 23, 42};
    vector<int> ans(4);

    for(int i = 0; i < 4; i++){
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cout.flush();
        cin >> ans[i];
    }

    do{
        bool flag = true;
        for(int i = 0; i < 4; i++){
            if(nums[i] * nums[i + 1] != ans[i]){
                flag = false;
            }
        }
        if(flag) break;
    }while(next_permutation(nums.begin(), nums.end()));

    cout << "! ";
    for(int i = 0; i < 6; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    cout.flush();
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int i=0, j=n-1;
        bool flag = true;
        while(i<=j){
            if(arr[i] != arr[j]){
                flag = false;
                break;
            }
            i++;
            j--;
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            int a = arr[i];
            int b = arr[j];

            int left = 0, right = n - 1;
            flag = true;
            while(left <= right){
                if(arr[left] == a){
                    left++;
                    continue;
                }
                if(arr[right] == a){
                    right--;
                    continue;
                }
                if(arr[left] != arr[right]){
                    flag = false;
                    break;
                }
                left++;
                right--;
            }

            if(flag){
                cout<<"YES"<<endl;
                continue;
            }

            left = 0;
            right = n - 1;
            flag = true;
            while(left <= right){
                if(arr[left] == b){
                    left++;
                    continue;
                }
                if(arr[right] == b){
                    right--;
                    continue;
                }
                if(arr[left] != arr[right]){
                    flag = false;
                    break;
                }
                left++;
                right--;
            }

            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}
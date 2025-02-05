#include<iostream>
using namespace std;

int main(){
    int n; 
    vector<int>arr;

    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int result = 0; int cnt = 0;
    for(int i=0; i<n; i++){
        cnt++;
        if(cnt >= arr[i]){
            result++;
            cnt = 0;
        }
    }

    cout << result;
}
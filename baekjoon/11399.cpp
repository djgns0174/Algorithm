#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const int a, const int b){
    return a < b;
}

int main(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);
    
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer += arr[j];
        }
    }
    
    cout << answer << endl;

    return 0;
}
#include<iostream>

using namespace std;

int main(void){

    int n, m;
    cin >> n >> m;
    
    vector<int>arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int>dp(m+1, 0);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        dp[arr[i]] = 1;
    }

    for(int i=1; i<arr[0]; i++){
        dp[i] = -1;
    }

    for(int i=arr[0]+1; i<=m; i++){

        bool isMoney = false;
        for(int j=0; j<n; j++){
            if(i == arr[j]) isMoney = true;
        }
        if(isMoney) continue;

        if(i < arr[0]) {
            dp[i] = -1;
            continue;
        }

        if(dp[i-arr[0]] == -1){
            dp[i] = -1; continue;
        }
        dp[i] = dp[i-arr[0]] + 1;

        for(int j=1; j<n; j++){
            if(i-arr[j] <=  0 || dp[i-arr[j]] == -1) continue;

            int temp = dp[i-arr[j]] + 1;
            if(temp < dp[i]) dp[i] = temp;
        }
    }

    cout << dp[m] << endl;
    
    return 0;
}
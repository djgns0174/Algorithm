#include<iostream>

using namespace std;

int main(void){

    int n, m;
    n = 3; m = 4;
    vector<int>arr ={3,5,7};
    // vector<int>arr(n);
    vector<int>dp(m+1, 10001);

    for(int i=0; i<n; i++){
        dp[arr[i]] = 1;
    }

    for(int i=arr[0]+1; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i-arr[j] > 0 && dp[i-arr[j]] != 10001){
                int temp = dp[i-arr[j]] + 1;
                if(temp < dp[i]){
                    dp[i] = temp;
                }
            }
        }
    }

    if(dp[m] == 10001) dp[m] = -1;
    cout << dp[m] << endl;

    return 0;
}
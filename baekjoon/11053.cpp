#include<iostream>
#include<algorithm>

using namespace std;

/*
    11055 와 논리구조 비슷함.
*/

int main(void){

    int n;
    cin >> n;

    int arr[1001];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int dp[1001] = {0,};
    dp[arr[1]] = 1;
    for(int i=2; i<=n; i++){

        int maxNum = 0;
        for(int j=1; j<arr[i]; j++){
            if(dp[j] == 0) continue;
            maxNum = max(maxNum, dp[j]);
        }

        dp[arr[i]] = maxNum + 1;
    }

    int answer = 0;
    for(int i=1; i<=n; i++){
        answer = max(answer, dp[arr[i]]);
    }
    cout << answer << "\n";
    
    return 0;
}
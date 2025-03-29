#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    int arr[1001];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int dp[1001] = {0,};
    dp[arr[1]] = arr[1];
    for(int i=2; i<=n; i++){
        int maxNum = -1;
        for(int j=1; j<arr[i]; j++){
            if(dp[j] == 0) continue;

            maxNum = max(dp[j], maxNum);
        }

        // cout << "maxNum : " << maxNum << endl;
        dp[arr[i]] = maxNum + arr[i];
        // cout << "dp["<<arr[i]<<"] : "<<dp[arr[i]] << endl;
    }

    //정답출력
    int answer = dp[arr[1]];
    for(int i=2; i<=n; i++){
        // cout << dp[arr[i]] << "\n";
        answer = max(answer, dp[arr[i]]);
    }
    cout << answer << "\n";

    
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n;
    cin >> n;
    
    int arr[10001] = {0,};
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    // 연속 3잔 방지
    bool sequenceCheck = false;

    // dp 초기값 세팅
    int dp[10001];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = arr[1] + arr[3];
    int tmp = arr[2] + arr[3];
    if(dp[3] < tmp){
        sequenceCheck = true;
        dp[3] = tmp;
    }

    if(n >= 4){
        for(int i=4; i<=n; i++){
            if(sequenceCheck){
                dp[i] = dp[i-2] + arr[i];
                if(dp[i] < dp[i-1]){
                    dp[i] = dp[i-1]; 
                    /*
                        예제 케이스에서 dp[6]일때 33과 26 비교필요
                    */
                }
                sequenceCheck = false;
            } else {
                dp[i] = dp[i-1] + arr[i];
                sequenceCheck = true;
            }
        }
    }
    
    cout << dp[n] << "\n";

    return 0;
}
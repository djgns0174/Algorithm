#include<iostream>

using namespace std;

int main(void){

    int n, m;
    cin >> n >> m;

    vector<vector<int> > inputArr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> inputArr[i][j];
        }
    }

    vector<vector<int> > dp(n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        dp[i][0] = inputArr[i][0];
    }
    
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            for(int k=0; k<3; k++){
                if(k==0 && i-1>=0){
                    dp[i][j] = inputArr[i][j] + dp[i-1][j-1];
                } else if(k==1){
                    if(dp[i][j] < inputArr[i][j] + dp[i][j-1]){
                        dp[i][j] = inputArr[i][j] + dp[i][j-1];
                    }
                } else if(k==2 && i+1<=n-1){
                    if(dp[i][j] < inputArr[i][j] + dp[i+1][j-1]){
                        dp[i][j] = inputArr[i][j] + dp[i+1][j-1];
                    }
                }
            }
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        if(result < dp[i][m-1]) result = dp[i][m-1];
    }

    cout << result << endl;
    
    return 0;
}
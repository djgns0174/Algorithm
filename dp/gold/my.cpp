#include<iostream>

using namespace std;

int main(void){

    int n, m;
    n = 3; m = 4;

    vector<vector<int> > inputArr = {{1,3,3,2}, {2,1,4,1}, {0,6,4,7}};
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
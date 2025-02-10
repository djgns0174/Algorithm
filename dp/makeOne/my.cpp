#include<iostream>
#include<climits>


using namespace std;

int main(void){

    int x;
    vector<int>dp;
    cin >> x;

    dp.resize(x+1, 0);

    dp[1] = 0; dp[2] = 1; dp[3] = 1; dp[5] = 1;

    for(int i=2; i<=x; i++){
        dp[i] = dp[i-1] + 1;
        int temp = INT_MAX;
        if(i%5 == 0) temp = dp[i/5] + 1;
        else if(i%3 == 0) temp = dp[i/3] + 1;
        else if(i%2 == 0) temp = dp[i/2] + 1;

        if(temp < dp[i]) dp[i] = temp;
    }

    cout << dp[x] << endl;
    
    return 0;
}
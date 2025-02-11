#include<iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;
    // n = 7;

    vector<int>inputArr(n);
    vector<int>dp(n, 1);

    for(int i=0; i<n; i++){
        cin >> inputArr[i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(inputArr[i] < inputArr[j]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int result = n - *std::max_element(dp.begin(), dp.end());
    cout << result << endl;

    return 0;
}
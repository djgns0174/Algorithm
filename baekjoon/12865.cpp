#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

struct Item {
    int weight;
    int value;
};

int dp[101][100001];

int main() {
    Item item[101];

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            int curWeight = item[i].weight;
            int curValue = item[i].value;

            if(curWeight > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], curValue + dp[i-1][j-curWeight]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}

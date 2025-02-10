#include<iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<int>k(n);

    for(int i=0; i<n; i++) cin >> k[i];

    vector<int>result(n);
    result[0] = k[0];
    result[1] = k[1];
    if(result[1] < result[0]) result[1] = result[0];

    for(int i=2; i<n; i++){
        result[i] = result[i-1];
        int temp = result[i-2] + k[i];
        if(result[i] < temp) result[i] = temp;
    }

    cout << result[n-1] << endl;
    
    return 0;
}
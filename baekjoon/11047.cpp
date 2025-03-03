#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n, k;
    int answer = 0;

    cin >> n >> k;
    vector<int> arr(n, 0);

    //입력데이터 받기
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target = k;
    for(int i=n-1; i>=0; i--){
        if(target == 0){
            break;
        }

        answer += target/arr[i];
        target = target%arr[i];
    }

    cout << answer << endl;
}
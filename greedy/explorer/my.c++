#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n = 5;
    // cin >> n;
    int arr[] = {3, 2, 2, 2, 1};
    // for(int i=0; i<n; i++){
        // cin >> arr[i];
    // }

    sort(arr, arr+n);

    int len = sizeof(arr) / sizeof(arr[0]);
    int result = 0; 
    int cnt = 0;
    int rest = len; 
    int max = 0;
    bool isGrouping = false;
    
    //첫번째 그룹형성
    int first = arr[0];
    max = first;
    rest--; cnt++;
    if (max == cnt){
        //그룹완성
        isGrouping = false;
        result++;
    } else {
        //그룹진행중
        isGrouping = true;
    }

    for(int i=1; i<len; i++){
        int newEx = arr[i];
        if(isGrouping){
            //그룹진행중
            max = newEx;
            rest--; cnt++;
            if(cnt == max){
                //그룹완성
                isGrouping = false;
                result++;
            }
        } else{
            //새그룹
            if(newEx > rest)
                break;
            max = newEx;
            rest--; cnt = 1;
            isGrouping = true;
        }
    }

    cout << result << endl; 
}
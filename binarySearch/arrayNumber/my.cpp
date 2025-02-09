#include<iostream>

using namespace std;

int main(){
    int n, x;
    n = 7; x = 2;

    vector<int> arr = {1,1,2,2,2,2,3};

    int start = 0; int end = n - 1;

    int min, result = 0;
    while (start <= end){
        min = (start + end) / 2;
        if(arr[min] == x && arr[min - 1] != x){
            while(1){
                if(arr[min] != x){
                    cout << result << endl;
                    return 0;
                }
                result ++; min ++;
            }
        } else if(arr[min] < x){
            start = min + 1;
        } else{
            end = min - 1;
        }
    }

    cout << -1 << endl;
    return 0;
}
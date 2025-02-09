#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    n = 4; m = 6;

    int arr[4] = {19, 15, 10 ,17};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int result = 0;
    int start = 0; int end = *std::max_element(arr, arr +arrSize) - 1;

    while(start <= end){
        result = (start + end) / 2;

        int temp = 0;
        int diff = 0;
        for(int i=0; i<arrSize; i++){
            if(arr[i] > result){
                diff = arr[i] - result;
                temp += diff;
            }
        }
        
        if(temp == m){
            cout << result << endl;
            return 0;
        } else if(temp > m){
            start = result + 1;
        } else{
            end = result - 1;
        }
    }

    cout << result << endl;

    return 0;
}
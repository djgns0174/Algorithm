#include<iostream>
#include<string>
using namespace std;

int main(){
    int result = 0;

    string input;
    cin >> input ;
    
    int len = input.length();
    int arr[len];


    for(int i=0; i<len; i++){
        arr[i] = input[i] - '0';
    }

    int first = arr[0]; int second = arr[1];
    if(first == 0 || first == 1 || second == 0 || second == 1){
        result = first + second;
    } else{
        result = first * second;
    }

    for(int i=2; i<len; i++){
        if(arr[i] == 0 || arr[i] == 1){
            result += arr[i];
        } else{
            result *= arr[i];
        }
    }

    cout << result << endl;
    return 0;
}
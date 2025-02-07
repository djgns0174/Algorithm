#include<iostream>
#include<utility>

using namespace std;

int main(void){
    int arr[] = {0,5,9,7,3,1,6,2,4,8};

    int min;
    for(int i=0; i<10; i++){
        min = arr[i];
        for(int j=i+1; j<10; j++){
            if(min > arr[j]){
                min = arr[j];
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i=0; i<10; i++){
        cout << arr[i];
    }
    cout << endl;
}
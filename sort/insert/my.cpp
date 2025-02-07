#include<iostream>
#include<utility>

using namespace std;

int main(void){
    int arr[] = {0,5,9,7,3,1,6,2,4,8};
    
    for(int i=0; i<10; i++){
        for(int j=i+1; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            } else break;
        }
    }

     for(int i=0; i<10; i++){
        cout << arr[i];
    }
    cout << endl;
}
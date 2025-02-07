#include<iostream>
#include<utility>

using namespace std;

int arr[] = {0,5,9,7,3,1,6,2,4,8};

void quickSort(int start, int end){

    if(start >= end){
        return;
    }

    int pivot = start;
    int left = start + 1; 
    int right = end;

    while(left <= right){
        while(arr[left] <= arr[pivot] && left < end) left++;
        while(arr[pivot] <= arr[right] && start < right) right--;
        if(right <= left) swap(arr[pivot], arr[right]);
        else swap(arr[left], arr[right]);
    }

    quickSort(start, left-1);
    quickSort(left, end);
}

int main(void){

    int start = 0;
    int end = 9;

    quickSort(start, end);
    
    for(int i=0; i<10; i++){
        cout << arr[i];
    }

    cout << endl;
}
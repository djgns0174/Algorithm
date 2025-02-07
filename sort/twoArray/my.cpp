#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> arr1(n);
    vector<int> arr2(n);

    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }

    int sizeArr1 = arr1.size();
    int sizeArr2 = arr2.size();

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for(int i=0; i<k; i++){
        int j = sizeArr1 - i - 1;
        
        swap(arr1[i], arr2[j]);
    }

    int result = 0;
    for(int i=0; i<n; i++){
        result += arr1[i];
    }

    cout << result << endl;
}
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int arrSize = arr.size();

    int result = 0;
    int start = 0; int end = *std::max_element(arr.begin(), arr.end()) - 1;

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
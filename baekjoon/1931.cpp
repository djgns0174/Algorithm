#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if (a.second == b.second) return a.first < b.first; // first 기준 정렬 추가
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), compare);

    int answer = 1;
    int prevEndTime = arr[0].second;
    int temp;
    for(int i=1; i<n; i++){
        if(prevEndTime <= arr[i].first){
            answer++; prevEndTime = arr[i].second;
        }
    }
    cout << answer << endl;
}
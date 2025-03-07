#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, v;
vector<pair<int, int> > arr;
vector<int> resultDfs;
vector<int> resultBfs;
vector<bool> visit;
queue<int> q;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void dfs(int x){
    resultDfs.push_back(x);
    for(int i=0; i<arr.size(); i++){
        if(arr[i].first == x){
            if(!visit[arr[i].second]){
                visit[arr[i].second] = true;
                dfs(arr[i].second);
            }
        }
    }
}

void bfs(){
    while(!q.empty()){
        int x = q.front();
        resultBfs.push_back(x);
        q.pop();
        for(int i=0; i<arr.size(); i++){
            if(arr[i].first == x){
                if(!visit[arr[i].second]){
                    q.push(arr[i].second);
                    visit[arr[i].second] = true;
                }
            }
        }
    }

}

int main(void){
    cin >> n >> m >> v;

    //visit 초기화
    for(int i=0; i<=n; i++){
        visit.push_back(false);
    }
    
    //입력받기
    int tmp1, tmp2;
    pair<int, int> tmpPair;
    for(int i=0; i<m; i++){
        cin >> tmp1 >> tmp2;
        tmpPair.first = tmp1; 
        tmpPair.second = tmp2;
        arr.push_back(tmpPair);
        tmpPair.first = tmp2;
        tmpPair.second = tmp1;
        arr.push_back(tmpPair);
    }

    //오름차순 정렬
    sort(arr.begin(), arr.end(), compare);

    //dfs 수행
    visit[v] = true;
    dfs(v);
    
    //visit 초기화
    for(int i=0; i<=n; i++){
        visit[i] = false;
    }

    //bfs 수행
    q.push(v);
    visit[v] = true;
    bfs();
    
    //dfs 출력
    for(int i=0; i<resultDfs.size(); i++){
        cout << resultDfs[i] << " ";
    }
    cout << endl;

    //bfs 출력
    for(int i=0; i<resultBfs.size(); i++){
        cout << resultBfs[i] << " ";
    }
    cout << endl;

    return 0;
}
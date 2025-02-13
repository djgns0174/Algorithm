#include<iostream>
#include<climits>

using namespace std;

int main(void){

    int n, m, c;
    cin >> n >> m >> c;

    // n = 3; m = 2; c = 1;
    vector<pair<int, int> > inputArr[m];
    for(int i=0; i<m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        inputArr[from].push_back({to, weight});  
    }

    vector<int> d(n, INT_MAX);
    d[c] = 0;
    vector<bool> visit(n, false);
    visit[c] = true;

    for(int i=0; i<inputArr[c].size(); i++){
        int to = inputArr[c][i].first;
        d[to] = inputArr[c][i].second;
    }

    int min = INT_MAX;
    int now;
    for(int i=1; i<n; i++){
        if(visit[i]) continue;
        if(d[i] < min){
            min = d[i];
            now = i;
        } 
    }

    while(!visit[now]){
        visit[now] = true;
        for(int i=0; i<inputArr[now].size(); i++){
            int to = inputArr[now][i].first;
            int temp = d[now] + inputArr[now][i].second;
            if(temp < d[to]) d[to] = temp;
        }

        int min = INT_MAX;
        for(int i=1; i<n; i++){
            if(!visit[i]){
                if(d[i] < min){
                    min = d[i];
                    now = i;
                }
            }
        }
    }

    pair<int, int> result;
    result.first = 0; result.second = 0;

    result.first = inputArr[c].size();
    int max = result.second;
    for(int i=0; i<result.first; i++){
        if(max < inputArr[c][i].second) max = inputArr[c][i].second;
    }
    result.second = max;

    cout << result.first << " " << result.second << endl;
    
    return 0;
}
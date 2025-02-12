#include<iostream>
#include<climits>

using namespace std;

int main(void){
    vector<pair<int, int> > graph[10];

    graph[1].push_back({2,2});
    graph[1].push_back({4,1});
    graph[1].push_back({3,5});

    graph[2].push_back({3,3});
    graph[2].push_back({4,2});

    graph[3].push_back({2,3});
    graph[3].push_back({6,5});

    graph[4].push_back({3,3});
    graph[4].push_back({5,1});

    graph[5].push_back({3,1});
    graph[5].push_back({6,2});

    vector<int> d(7, INT_MAX-1);
    d[1] = 0;
    vector<bool> visit(7,false);

    int start = 1;
    visit[start] = true;
    for(int i=0; i<graph[start].size(); i++){
        int adjNode = graph[start][i].first;
        d[adjNode] = graph[start][i].second;
    }

    int now;
    int min = d[2];
    for(int i=2; i<d.size(); i++){
        if(d[i] < min) {
            min = d[i];
            now = i;
        }
    }

    while(visit[now] == false){
        visit[now] = true;
        for(int i=0; i<graph[now].size(); i++){
            int adjNode = graph[now][i].first;
            int temp = graph[now][i].second + d[now];
            if(temp < d[adjNode]){
                d[adjNode] = temp;
            }
        }
        min = INT_MAX;
        for(int i=2; i<d.size(); i++){
            if(visit[i] == true) continue;
            if(d[i] < min) {
                min = d[i];
                now = i;
            }
        }
    }

    for(int i=1; i<7; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
//우선순위 큐 이용

#include<iostream>

using namespace std;

vector<pair<int, int> >graph[10];
vector<int> d(7, INT_MAX-1);
priority_queue<pair<int, int> > pq;

int init(){
    graph[1].push_back({2,2});
    graph[1].push_back({1,4});
    graph[1].push_back({5,3});

    graph[2].push_back({3,3});
    graph[2].push_back({2,4});

    graph[3].push_back({3,2});
    graph[3].push_back({5,6});

    graph[4].push_back({3,3});
    graph[4].push_back({1,5});

    graph[5].push_back({1,3});
    graph[5].push_back({2,6});

    d[1] = 0;
    pq.push({0,1});

    return 0;
}

int main(void){

    init();

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        if(d[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++){
            int to = graph[now][i].first;
            int temp = graph[now][i].second + d[now];
            if(temp < d[to]) {
                d[to] = temp;
                pq.push({-d[to], to});
            }
        }
    }

    for(int i=1; i<7; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    
    return 0;
}
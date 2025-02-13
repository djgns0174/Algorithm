//우선순위 큐 이용

#include<iostream>

using namespace std;

vector<pair<int, int> >graph[10];
vector<int> d(7, INT_MAX-1);
priority_queue<pair<int, int> > pq;

int init(){
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

    d[1] = 0;
    pq.push({1,0});

    return 0;
}

int main(void){

    init();

    while(!pq.empty()){
        int now = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++){
            int to = graph[now][i].first;
            int temp = graph[now][i].second + d[now];
            if(temp < d[to]) {
                d[to] = temp;
                pq.push({to, -d[to]});
            }
        }
    }

    for(int i=1; i<7; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    
    return 0;
}
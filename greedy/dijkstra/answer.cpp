#include<iostream>
#include<climits>

using namespace std;

int n, m, start;
vector<pair<int, int> > graph[100001];
int d[100001];

void dijkstar(int start){
    //우선순위 큐 이용
    priority_queue<pair<int, int> >pq;
    pq.push({0, start});

    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void){
    dijkstar(start);
}
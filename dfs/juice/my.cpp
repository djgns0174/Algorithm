#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int main(void){
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int> > arr(n, vector<int>(m));

    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        for(int j=0; j<m; j++){
            arr[i][j] = input[j] - '0';
        }
    }

    queue<pair<int, int> > q;
    vector<vector<bool> > visit(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0)
                visit[i][j] = false;
            else
                visit[i][j] = true;
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visit[i][j]){
                // 아이스크림 시작
                visit[i][j] = true;
                q.push({i,j});
                result ++;

                while(!q.empty()){
                    //인접노드 탐색
                    pair<int, int> p = q.front();
                    q.pop();
                    int y = p.first;
                    int x = p.second;

                    if(y+1 < n && !visit[y+1][x]){
                        q.push({y+1, x});
                        visit[y+1][x] = true;
                    } 
                    
                    if(x+1 < m && !visit[y][x+1]){
                        q.push({y, x+1});
                        visit[y][x+1] = true;
                    }                    
                }
            }
        }
    }    

    cout << result << endl;
    
    return 0;
}
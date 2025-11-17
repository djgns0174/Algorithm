#include<iostream>
#include<vector>

using namespace std;

int answer;

void dfs(int depth, int cur, vector<bool>visit, vector<pair<int,int>> arr)
{
    answer = max(answer, depth);

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i].first == cur)
        {
            int next = arr[i].second;
            if(visit[next]) continue; // 이미 방문한 노드라면

            visit[cur] = true;
            dfs(depth+1, next, visit, arr);
            visit[cur] = false;
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    vector<int> answers; //정답 저장용 벡터

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        cin >> N >> M;

        answer = 0;

        vector<pair<int,int>>arr;

        for(int i=0; i<M; i++)
        {
            int x, y;
            cin >> x >> y;
            
            arr.push_back({x,y});
            arr.push_back({y,x});
        } 

        vector<bool>visit(11, false);
        for(int i=0; i<arr.size(); i++)
        {
            int cur = arr[i].first;
            visit[cur] = true;

            int next = arr[i].second;
            dfs(1, next, visit, arr);

            visit[cur] = false;
        }

        answers.push_back(answer+1);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}
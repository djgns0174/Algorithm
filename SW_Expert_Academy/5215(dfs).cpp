#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;
int answer;

void func(int start, int cur_score, int cur_calorie, vector<bool>visit, vector<pair<int,int>> arr)
{
    vector<bool> cp_visit = visit;

    if(cur_calorie > L) return;

    answer = max(answer, cur_score);

    for(int i=start+1; i<N; i++)
    {
        if(cp_visit[i]) continue;
        int next_score = cur_score + arr[i].first;
        int next_calorie = cur_calorie + arr[i].second;

        // cout << endl;
        // cout << i << "번째 재료 담음" << endl;
        // cout << "현재 누적 점수 : " << next_score << endl;
        // cout << "현재 누적 칼로리 : " << next_calorie << endl; //test
        // cout << endl;

        cp_visit[i] = true;
        func(i, next_score, next_calorie, cp_visit, arr);
        cp_visit = visit;
    }

    return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<int> answers;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> L;

        vector<pair<int,int>> arr;
        vector<bool>visit(N, false);
        
        answer = -1;
        
        for(int i=0; i<N; i++) //입력 받기
        {
            pair<int,int> input;
            cin >> input.first >> input.second;
            arr.push_back(input);
        }

        for(int i=0; i<N; i++) //DFS
        {
            int score = arr[i].first;
            int calorie = arr[i].second;

            visit[i] = true;
            func(i, score, calorie, visit, arr);
            visit[i] = false;
        }

        answers.push_back(answer);
	}

    for(int i=0; i<answers.size(); i++)
    {
        cout << "#" << i+1 << " " << answers[i] << endl;
    }

	return 0;
}
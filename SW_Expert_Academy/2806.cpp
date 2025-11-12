#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int answer;

void dfs(int row, vector<int> r)
{
    if(row == N)
    {
        answer++;
        return;
    }

    for(int col=0; col<N; col++)
    {
        bool is_continue = false;
        for(int i=0; i<row; i++)
        {
            if(r[i] == col) //열 조건 확인
                is_continue = true;

            if(abs(i-row) == abs(r[i]-col)) //대각선 조건 확인
                is_continue = true;
        }

        if(is_continue) continue;

        r[row] = col;
        dfs(row+1, r);
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
        answer = 0;
        cin >> N;
        
        vector<int>r(N, -1);
        dfs(0, r);

        answers.push_back(answer);
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}